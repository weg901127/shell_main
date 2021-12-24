#include "../../micro_shell.h"
//함수들어가서 입력받아요 readline
//다받으면 넘겨줘요 파이프로
void	do_fork(t_storage *bag, char *str, int cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (cmd != 0)
			dup2(bag->pipe_fds[(cmd - 1) * 2], 0);
		if (cmd != bag->num_of_cmds - 1)
			dup2(bag->pipe_fds[cmd * 2 + 1], 1);
		for (int i = 2; i > -1 ; i--)
			close(bag->pipe_fds[i]);
		char	*argv2[] = {my_which(bag, str),NULL};
		execve(my_which(bag, str), argv2, get_environ(bag));
	}
	waitpid(-1, 0, 0);
}

void	pipex(t_storage *bag, char **args)
{
	int		i;

	bag->num_of_cmds = ft_splitcnt(args);
	if (!bag->num_of_cmds)
		return ;
	bag->pipe_fds = (int *)malloc(sizeof(int) * bag->num_of_cmds - 1);
	for (int i = 0; i < bag->num_of_cmds - 1; i++)
		pipe(bag->pipe_fds + 2*i);
	i = 0;
	while (args[i])
	{
		do_fork(bag, args[i], i);
		i++;
	}
}
