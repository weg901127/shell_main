#include "../../micro_shell.h"

void	fork_grandchild(t_storage *bag, char *arg, int idx)
{
	print_error_and_exit("pipe() has failed", NULL, pipe(bag->pipe_fds[idx]));
	bag->grandchild_pids[idx] = fork();
	print_error_and_exit("fork() has failed", NULL, bag->grandchild_pids[idx]);
	if (!bag->grandchild_pids[idx])
	{
		if (idx != bag->num_of_cmds - 1)
			close(bag->pipe_fds[idx][PIPE_RD_FD]);
		if (idx != 0)
			close(bag->pipe_fds[idx -1][PIPE_WR_FD]);
		redirect_fds(bag, idx);
		execve_cmd(bag, arg);
	}
	//parent process
	if (idx != 0)
	{	
		close(bag->pipe_fds[idx - 1][PIPE_RD_FD]);
		close(bag->pipe_fds[idx - 1][PIPE_WR_FD]);
	}
	//remove heredoc_tmp_file 
}
