/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 08:50:23 by sehee             #+#    #+#             */
/*   Updated: 2021/12/08 13:45:36 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

void	pipex(int argc, char **argv, char **envp)
{
	t_storage	info;
	pid_t		pid;
	int			status;
	int			cmd_idx;

	parse_arguments(argc, argv, &info);
	pid = fork();
	print_error_and_exit("fork() has failed", NULL, pid);
	if (pid == 0)
	{
		fork_1st_grandchild(&info, envp);
		cmd_idx = 1;
		while (cmd_idx < info.num_of_cmds - 1)
			fork_nth_grandchild(&info, cmd_idx++, envp);
		fork_last_grandchild(&info, envp);
		wait_and_exit_for_grandchildren(info);
	}
	else
	{
		waitpid(pid, &status, 0);
		exit_for_child(status);
	}
}
