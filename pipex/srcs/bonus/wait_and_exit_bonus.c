/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_and_exit_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 09:48:18 by sehee             #+#    #+#             */
/*   Updated: 2021/09/26 10:23:01 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	exit_for_child(int status)
{
	if (wifexited(status))
		exit(wexitstatus(status));
	else if (wifsignaled(status))
		exit(wtermsig(status));
	else
		exit(EXIT_FAILURE);
}

void	wait_and_exit_for_grandchildren(t_storage info)
{
	int		status;
	int		cmdn_status;
	pid_t	reaped_pid;

	reaped_pid = 0;
	while (reaped_pid != -1)
	{
		reaped_pid = waitpid(-1, &status, 0);
		if (reaped_pid == info.grandchild_pids[info.num_of_cmds - 1])
			cmdn_status = status;
	}
	exit_for_child(cmdn_status);
}
