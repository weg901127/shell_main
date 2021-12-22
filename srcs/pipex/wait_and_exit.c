#include "../../micro_shell.h"

void	exit_for_child(int status)
{
	if (wifexited(status))
		exit(wexitstatus(status));
	else if (wifsignaled(status))
		exit(wtermsig(status));
	else
		exit(EXIT_FAILURE);
}

void	wait_and_exit_for_grandchildren(t_storage bag)
{
	int		status;
	int		cmdn_status;
	pid_t	reaped_pid;

	reaped_pid = 0;
	while (reaped_pid != -1)
	{
		reaped_pid = waitpid(-1, &status, 0);
		if (reaped_pid == bag.grandchild_pids[bag.num_of_cmds - 1])
			cmdn_status = status;
	}
	exit_for_child(cmdn_status);
}
