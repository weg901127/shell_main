#include "../../micro_shell.h"

static void	malloc_grandchild_pids(t_storage *bag)
{
	bag->grandchild_pids = (pid_t *)ft_calloc(bag->num_of_cmds, sizeof(pid_t));
	if (!bag->grandchild_pids)
		print_error_and_exit("malloc() has failed", NULL, -1);
}

static void	malloc_pipe_fds(t_storage *bag)
{
	(void)bag;
	/*
	int	i;

	bag->pipe_fds = (int **)ft_calloc((bag->num_of_cmds - 1), sizeof(int *));
	if (!bag->pipe_fds)
		print_error_and_exit("malloc() has failed", NULL, -1);
	i = 0;
	while (i < bag->num_of_cmds - 1)
	{
		bag->pipe_fds[i] = (int *)ft_calloc(2, sizeof(int));
		if (!bag->pipe_fds[i])
		{
			ft_malloc_fail_int(bag->pipe_fds, bag->num_of_cmds - 1);
			print_error_and_exit("malloc() has failed", NULL, -1);
		}
		i++;
	}
	*/
}

void	allocate_before_fork(t_storage *bag, char **args)
{
	bag->num_of_cmds = count_str_array(args);
	malloc_grandchild_pids(bag);
	malloc_pipe_fds(bag);
}
