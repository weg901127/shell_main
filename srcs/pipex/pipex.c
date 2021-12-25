#include "../../micro_shell.h"
//함수들어가서 입력받아요 readline
//다받으면 넘겨줘요 파이프로
char **set_argv(t_storage *bag, char *str)
{
	char	**tmp;
	char	*cmd_tmp;

	tmp = ft_split(str, ' ');
	cmd_tmp = my_which(bag, tmp[0]);
	free(tmp[0]);
	tmp[0] = cmd_tmp;
	return(tmp);
}
/*
void	do_fork(t_storage *bag, char *str, int cmd)
{
	pid_t	pid;
	int		pipe_cnt;
	char	**argv;

	pipe_cnt = (bag->num_of_cmds - 1) * 2;
	pid = fork();
	if (pid == 0)
	{
		if (cmd != 0)
			dup2(bag->pipe_fds[(cmd - 1) * 2], 0);
		if (cmd != bag->num_of_cmds - 1)
			dup2(bag->pipe_fds[cmd * 2 + 1], 1);
		while (pipe_cnt)
			close(bag->pipe_fds[--pipe_cnt]);
		argv = set_argv(bag, str);
		execve(argv[0], argv, get_environ(bag));
		ft_putstr_fd(str, 2);
		//exit(0);
	}
}
*/
void	do_fork(t_storage *bag, char *str, int cmd, int *fd_in)
{
	
	int		p[2];
	char	**argv;
	pid_t	pid;

	pipe(p);
	if ((pid = fork()) == -1)
	{
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		dup2(*fd_in, 0); //change the input according to the old one 
		if (cmd != bag->num_of_cmds - 1)
			dup2(p[1], 1);
		close(p[0]);
		argv = set_argv(bag, str);
		execve(argv[0], argv, get_environ(bag));
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
		close(p[1]);
		*fd_in = p[0]; //save the input for the next command
	}
}
void	pipex(t_storage *bag, char **args)
{
	int		i;
	int		fd_in;
	pid_t	pid;
	
	fd_in = 0;
	bag->num_of_cmds = ft_splitcnt(args);
	if (!bag->num_of_cmds)
		return ;
	//bag->pipe_fds = (int *)malloc(sizeof(int) * (bag->num_of_cmds - 1) * 2);
	//i = 0;
	//while (i < bag->num_of_cmds - 1)
	//	pipe(bag->pipe_fds + 2 * i++);
	i = -1;
	//signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid==0)
	{
		while (args[++i])
			do_fork(bag, args[i], i, &fd_in);
		i = bag->num_of_cmds - 1;
		/*
		while (--i > -1)
		{
			close(bag->pipe_fds[2 * i]);
			close(bag->pipe_fds[2 * i + 1]);
		}
		*/
		waitpid(-1, 0, 0);
		exit(0);
	}
	else
		waitpid(pid,0,0);
	//close(1);
	free(bag->pipe_fds);
}
