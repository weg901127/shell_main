/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 09:36:18 by sehee             #+#    #+#             */
/*   Updated: 2021/09/27 02:59:44 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	malloc_grandchild_pids(t_storage *info)
{
	info->grandchild_pids = (pid_t *)malloc(sizeof(pid_t) * info->num_of_cmds);
	if (!info->grandchild_pids)
		print_error_and_exit("malloc() has failed", NULL, -1);
}

void	malloc_pipe_fds(t_storage *info)
{
	int	i;

	info->pipe_fds = (int **)malloc(sizeof(int *) * (info->num_of_cmds - 1));
	if (!info->pipe_fds)
		print_error_and_exit("malloc() has failed", NULL, -1);
	i = 0;
	while (i < info->num_of_cmds - 1)
	{
		info->pipe_fds[i] = (int *)malloc(sizeof(int) * 2);
		if (!info->pipe_fds[i])
		{
			ft_malloc_fail_int(info->pipe_fds, info->num_of_cmds);
			print_error_and_exit("malloc() has failed", NULL, -1);
		}
		i++;
	}
}

void	malloc_cmd_args(t_storage *info, char **argv)
{
	int	i;

	info->cmd_args = (char ***)malloc(sizeof(char **) * (info->num_of_cmds));
	if (!info->cmd_args)
		print_error_and_exit("malloc() has failed", NULL, -1);
	i = 0;
	if (info->heredoc_flag == 1)
	{
		info->cmd_args[0] = split_cmd(argv[3]);
		info->cmd_args[1] = split_cmd(argv[4]);
		return ;
	}
	while (i < info->num_of_cmds)
	{
		info->cmd_args[i] = split_cmd(argv[i + 2]);
		i++;
	}	
}
