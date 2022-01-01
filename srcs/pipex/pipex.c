#include "../../micro_shell.h"

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
	close(pip[0]);
}

void	handle_pipe_parent(t_storage *bag, int *pip, int cmd, pid_t pid)
{
	int	stat;

	waitpid(pid, &stat, 0);
	if (WEXITSTATUS(stat) == SYNTAX_ERR)
		ft_putstr_fd("SyntexError\n",2);
	else if (WEXITSTATUS(stat) == ERROR)	
		ft_putstr_fd("Error\n",2);
	else if (WIFSIGNALED(stat))
	{
		if (WTERMSIG(stat) == 3)
			ft_putstr_fd("Quit: 3", 1);
		ft_putstr_fd("\n", 1);
	}
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
		signal(SIGQUIT, SIG_DFL);
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
	if (do_not_fork(bag, args[0]))
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
