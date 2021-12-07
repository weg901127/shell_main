/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_grandchildren_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 09:59:18 by sehee             #+#    #+#             */
/*   Updated: 2021/09/27 14:57:43 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	fork_1st_grandchild(t_storage *info, char **envp)
{
	print_error_and_exit("pipe() has failed", NULL, pipe(info->pipe_fds[0]));
	info->grandchild_pids[0] = fork();
	print_error_and_exit("fork() has failed", NULL, info->grandchild_pids[0]);
	if (info->grandchild_pids[0] == 0)
	{
		close(info->pipe_fds[0][PIPE_RD_FD]);
		redirect_fds_in_1st_grandchild(info);
		execve_with_path(split_path_env(envp), info->cmd_args[0], envp);
	}
}

void	fork_nth_grandchild(t_storage *info, int cmd_idx, char **envp)
{
	print_error_and_exit("pipe() has failed", NULL, \
		pipe(info->pipe_fds[cmd_idx]));
	info->grandchild_pids[cmd_idx] = fork();
	print_error_and_exit("fork() has failed", NULL, \
		info->grandchild_pids[cmd_idx]);
	if (info->grandchild_pids[cmd_idx] == 0)
	{
		close(info->pipe_fds[cmd_idx - 1][PIPE_WR_FD]);
		close(info->pipe_fds[cmd_idx][PIPE_RD_FD]);
		redirect_fds_in_nth_grandchild(info, cmd_idx);
		execve_with_path(split_path_env(envp), info->cmd_args[cmd_idx], envp);
	}
	close(info->pipe_fds[cmd_idx - 1][PIPE_RD_FD]);
	close(info->pipe_fds[cmd_idx - 1][PIPE_WR_FD]);
}

void	fork_last_grandchild(t_storage *info, char **envp)
{
	int	last_cmd_idx;

	last_cmd_idx = info->num_of_cmds - 1;
	info->grandchild_pids[last_cmd_idx] = fork();
	print_error_and_exit("fork() has failed", NULL, \
		info->grandchild_pids[last_cmd_idx]);
	if (info->grandchild_pids[last_cmd_idx] == 0)
	{
		close(info->pipe_fds[last_cmd_idx - 1][PIPE_WR_FD]);
		redirect_fds_in_last_grandchild(info);
		execve_with_path(split_path_env(envp), info->cmd_args[last_cmd_idx], \
			envp);
	}
	close(info->pipe_fds[last_cmd_idx - 1][PIPE_RD_FD]);
	close(info->pipe_fds[last_cmd_idx - 1][PIPE_WR_FD]);
	if (info->heredoc_flag == 1)
		print_error_and_exit("unlink() has failed", info->infile_name, \
			unlink(info->infile_name));
}
