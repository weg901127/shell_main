#include "../../micro_shell.h"

static void	malloc_grandchild_pids(t_storage *bag)
{
	bag->grandchild_pids = (pid_t *)malloc(sizeof(pid_t) * bag->num_of_cmds);
	if (!bag->grandchild_pids)
		print_error_and_exit("malloc() has failed", NULL, -1);
}

static void	malloc_pipe_fds(t_storage *bag)
{
	int	i;

	bag->pipe_fds = (int **)malloc(sizeof(int *) * (bag->num_of_cmds - 1));
	if (!bag->pipe_fds)
		print_error_and_exit("malloc() has failed", NULL, -1);
	i = 0;
	while (i < bag->num_of_cmds - 1)
	{
		bag->pipe_fds[i] = (int *)malloc(sizeof(int) * 2);
		if (!bag->pipe_fds[i])
		{
			ft_malloc_fail_int(bag->pipe_fds, bag->num_of_cmds - 1);
			print_error_and_exit("malloc() has failed", NULL, -1);
		}
		i++;
	}
}

void	allocate_before_fork(t_storage *bag, char **args)
{
	bag->num_of_cmds = count_str_array(args);
	malloc_grandchild_pids(bag);
	malloc_pipe_fds(bag);
}