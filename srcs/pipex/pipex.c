#include "../../micro_shell.h"

// argc, argv 는 readline 인자로 바꾸자!??
void	pipex(t_storage *bag, char **args)
{
	int		i;
	int		status;
	pid_t	pid;
	char	*buf;
	
	i = 0;
	allocate_before_fork(bag, args);
	pid = fork();
	print_error_and_exit("fork() has failed", NULL, pid);
	if (pid == 0)
	{
		while (args[i])
		{
			buf = ft_strtrim(args[i], " ");
			fork_grandchild(bag, args[i], i);
			i++;
			free(buf);
		}
		wait_and_exit_for_grandchildren(*bag);
	}
	else
	{
		waitpid(pid, &status, 0);
		exit_for_child(status);
	}
}
