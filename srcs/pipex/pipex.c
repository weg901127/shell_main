#include "../../micro_shell.h"
//함수들어가서 입력받아요 readline
//다받으면 넘겨줘요 파이프로
char **set_argv(t_storage *bag, char *str)
{
	char	**tmp;
	char	*cmd_tmp;

	tmp = ft_split(str, ' ');
	if (ft_strchr(tmp[0], '<'))
		exit(SYNTAX_ERR);
	cmd_tmp = my_which(bag, tmp[0]);
	free(tmp[0]);
	tmp[0] = cmd_tmp;
	return(tmp);
}
void	my_execve(t_storage *bag, char	*str)
{
	char	**argv;
	int		i;

	i = 0;
	argv = set_argv(bag, str);
	while (argv[i])
	{
		if (ft_strchr(argv[i], '<'))
		{
			free(argv[i]);
			argv[i] = NULL;
		}
		i++;
	}
	execve(argv[0], argv, get_environ(bag));
	exit(EXIT_FAILURE);
}
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
			bag->redirect_output++;
			res |= 1;
		}
		else if (buf && buf[0] == '>' && buf[1] == '>')
		{
			bag->append++;
			res |= 1;
		}
		buf = ft_strchr(buf + 1, '>');
	}
	return (res);
}
char	*get_last_redirect(char *str)
{
	char	*buf;
	char	*res;

	res = NULL;
	buf = str;
	while (buf)
	{
		buf = ft_strchr(buf, '<');
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
	int		fd;	

	buf = ft_strdup(get_last_redirect(str) + 1);
	buf = ft_strtrim(buf, " ");
	fd = open(buf, O_RDONLY);
	if (fd == -1)
		exit(1);
	dup2(fd, 0);
	close(fd);
}

void	heredoc_rdline(char *buf, int fd)
{
	char	*line;
	int		pid;

	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, handler_int_heredoc);
		while (true)
		{
			line = readline("> ");
			if (ft_strlen(line) && ft_strncmp(buf, line, ft_strlen(line)) == 0)
			{
				close(fd);
				break;
			}
			if (line)
			{
				write(fd, line, ft_strlen(line));
				write(fd,"\n", 1);
			}
		}
		exit(0);
	}
	else
		wait(NULL);
}

void	rd_heredoc(char *str)
{
	char	*buf;
	int		fd;	

	buf = ft_strdup(get_last_redirect(str) + 1);
	buf = ft_strtrim(buf, " ");
	if (!ft_strlen(buf))
		exit(SYNTAX_ERR);
	fd = open(".hd________", O_RDWR|O_CREAT, S_IRUSR | S_IWUSR);
	signal(SIGINT, SIG_IGN);
	heredoc_rdline(buf, fd);
	signal(SIGINT, handler_int_child);
	fd = open(".hd________",O_RDONLY);
	if (fd == -1)
		exit(1);
	dup2(fd, 0);
	close(fd);
	unlink(".hd________");
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

void	handle_pipe_child(t_storage *bag, int *pip, int cmd, char *str)
{
	if (has_redirect(bag, str))
		process_redirect_input(bag, str);
	else
		dup2(bag->pipe_old, 0);
	if (cmd != bag->num_of_cmds - 1)
		dup2(pip[1], 1);
	close(pip[0]);
}

void	handle_pipe_parent(t_storage *bag, int *pip)
{
	int	stat;

	//sehhong: 해당 child를 기다리는 거면 pid를 지정해서 기다리는 게 낫지않나요?
	waitpid(-1, &stat, 0);
	if (WEXITSTATUS(stat) == 99)	
		ft_putstr_fd("SyntexError\n",2);
	close(pip[1]);
	bag->pipe_old = pip[0];
}

void	do_fork(t_storage *bag, char *str, int cmd)
{
	int		p[2];
	pid_t	pid;

	pipe(p);
	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	else if (pid == 0)
	{
		signal(SIGINT, handler_int_child);
		handle_pipe_child(bag, p, cmd, str);
		my_execve(bag, str);
	}
	else
		handle_pipe_parent(bag, p);
}

void	pipex(t_storage *bag, char **args)
{
	int		i;
	pid_t	pid;
	
	bag->pipe_old = 0;
	bag->num_of_cmds = ft_splitcnt(args);
	if (!bag->num_of_cmds)
		return ;
	//sehhong: 사용?
	i = -1;
	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == 0)
	{
		while (args[++i])
			do_fork(bag, args[i], i);
		//i = bag->num_of_cmds - 1;
		//sehhong: ??
		exit(0);
	}
	else
		waitpid(pid,0,0);
	signal(SIGINT, handler_int);
}
