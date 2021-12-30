#include "../../micro_shell.h"

int		has_redirect(t_storage *bag, char *str)
{
	int		res;
	char	*buf;

	res = 0;
	buf = ft_strchr(str, '<');
	while (buf != NULL)
	{
		if (buf && buf[0] == '<' && buf[1] != '<')
		{
			(bag->redirect_input)++;
			res |= 1;
		}
		else if (buf && buf[0] == '<' && buf[1] == '<')
		{
			(bag->heredoc)++;
			buf = buf + 1;
			res |= 1;
		}
		buf = ft_strchr(buf + 1, '<');
	}
	buf = ft_strchr(str, '>');
	while (buf != NULL)
	{
		if (buf && buf[0] == '>' && buf[1] != '>')
		{
			(bag->redirect_output)++;
			res |= 1;
		}
		else if (buf && buf[0] == '>' && buf[1] == '>')
		{
			(bag->append)++;
			buf = buf + 1;
			res |= 1;
		}
		buf = ft_strchr(buf + 1, '>');
	}
	return (res);
}

char	*get_last_redirect(char *str, int target)
{
	char	*buf;
	char	*res;

	res = NULL;
	buf = str;
	while (buf)
	{
		buf = ft_strchr(buf, target);
		if (buf)
		{
			res = buf;
			buf = buf + 1;
		}
	}
	return res;
}

void	rd_input(char *str)
{
	char	*buf;
	char	**split;
	int		fd;	

	buf = ft_strdup(get_last_redirect(str, '<') + 1);
	split = ft_split(buf, ' ');
	fd = open(split[0], O_RDONLY);
	if (fd == -1)
		exit(100);
	dup2(fd, 0);
	close(fd);
}

void	process_redirect_input(t_storage *bag, char *str)
{
	if ((bag->redirect_input != 0 && bag->heredoc != 0)
			|| bag->redirect_input > 1 || bag->heredoc > 1)
		exit(SYNTAX_ERR);
	else if (bag->redirect_input)
		rd_input(str);
	else if (bag->heredoc)
		rd_heredoc(str);
}

void	rd_output(char *str)
{
	char	*buf;
	char	**split;
	int		fd;	

	buf = ft_strdup(get_last_redirect(str, '>') + 1);
	split = ft_split(buf, ' ');
	fd = open(split[0], O_RDWR|O_CREAT|O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		exit(100);
	dup2(fd, 1);
	close(fd);
}

void	rd_append(char *str)
{
	char	*buf;
	char	**split;
	int		fd;	

	buf = ft_strdup(get_last_redirect(str, '>') + 1);
	split = ft_split(buf, ' ');
	fd = open(split[0], O_RDWR|O_CREAT|O_APPEND, S_IRUSR | S_IWUSR);
	if (fd == -1)
		exit(100);
	dup2(fd, 1);
	close(fd);
}

void	process_redirect_output(t_storage *bag, char *str, int *pip)
{
	(void) pip;
	if ((bag->redirect_output != 0 && bag->append != 0)
			|| bag->redirect_output > 1 || bag->append > 1)
		exit(SYNTAX_ERR);
	else if (bag->redirect_output)
		rd_output(str);
	else if (bag->append)
		rd_append(str);
}

void	handle_pipe_child(t_storage *bag, int *pip, int cmd, char *str)
{
	if (bag->redirect_input || bag->heredoc)
		process_redirect_input(bag, str);
	else
		dup2(bag->pipe_old, 0);
	if (bag->redirect_output || bag->append)
		process_redirect_output(bag, str, pip);
	else
		if (cmd != bag->num_of_cmds - 1)
			dup2(pip[1], 1);
	//close(pip[0]);
}

void	handle_pipe_parent(t_storage *bag, int *pip, int cmd, pid_t pid)
{
	int	stat;

	waitpid(pid, &stat, 0);
	if (WEXITSTATUS(stat) == 99)
		ft_putstr_fd("SyntexError\n",2);
	else if (WEXITSTATUS(stat) == 100)	
		ft_putstr_fd("Error\n",2);
	else if (WTERMSIG(stat) == SIGINT)
		ft_putstr_fd("\n", 2);
	else if (WTERMSIG(stat) == SIGQUIT)
		ft_putstr_fd("Quit: 3\n", 2);
	if (cmd == bag->num_of_cmds - 1)
		bag->last_exit_status = WEXITSTATUS(stat);
	close(pip[1]);
	bag->pipe_old = pip[0];
	bag->redirect_input = 0;
	bag->redirect_output = 0;
	bag->append = 0;
	bag->heredoc = 0;
}

void	do_fork(t_storage *bag, char *str, int cmd)
{
	int		p[2];
	pid_t	pid;

	pipe(p);
	has_redirect(bag, str);
	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	else if (pid == 0)
	{
		signal(SIGINT, handler_int_child);
		signal(SIGQUIT, handler_quit);
		handle_pipe_child(bag, p, cmd, str);
		my_execve(bag, str);
	}
	else
		handle_pipe_parent(bag, p, cmd, pid);
}

void	pipex(t_storage *bag, char **args)
{
	int		i;
	pid_t	pid;
	int		exit_status;
	int		status;
	
	i = -1;
	exit_status = EXIT_SUCCESS;
	bag->pipe_old = 0;
	bag->num_of_cmds = ft_splitcnt(args);
	if (bag->num_of_cmds == 1 && is_builtin(bag, args[0]))
	{	
		exit_status = execve_builtin(bag, args[0]);
		set_environ(bag, exit_status);
		return ;
	}
	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid==0)
	{
		while (args[++i])
			do_fork(bag, args[i], i);
		exit(bag->last_exit_status);
	}
	else
	{
		waitpid(pid, &status, 0);
		bag->last_exit_status = WEXITSTATUS(status);
		set_environ(bag, bag->last_exit_status);
	}
	signal(SIGINT, handler_int);
}
