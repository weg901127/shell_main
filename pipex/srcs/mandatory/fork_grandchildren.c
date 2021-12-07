/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_grandchildren.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:27:40 by sehhong           #+#    #+#             */
/*   Updated: 2021/12/04 09:54:01 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fork_1st_grandchild(t_storage *info, char **envp)
{
	print_error_and_exit("pipe() has failed", NULL, pipe(info->pipe_fds));
	info->pids[0] = fork();
	print_error_and_exit("fork() has failed", NULL, info->pids[0]);
	if (info->pids[0] == 0)
	{
		close(info->pipe_fds[PIPE_RD_FD]);
		redirect_fds_in_1st_grandchild(info);
		execve_with_path(split_path_env(envp), info->cmd1_arg, envp);
	}
}

void	fork_2nd_grandchild(t_storage *info, char **envp)
{
	info->pids[1] = fork();
	print_error_and_exit("fork() has failed.\n", NULL, info->pids[1]);
	if (info->pids[1] == 0)
	{
		close(info->pipe_fds[PIPE_WR_FD]);
		redirect_fds_in_2nd_grandchild(info);
		execve_with_path(split_path_env(envp), info->cmd2_arg, envp);
	}
	close(info->pipe_fds[PIPE_RD_FD]);
	close(info->pipe_fds[PIPE_WR_FD]);
}
