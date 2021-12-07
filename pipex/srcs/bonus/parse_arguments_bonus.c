/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:42:24 by sehee             #+#    #+#             */
/*   Updated: 2021/09/27 15:00:48 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	parse_arguments_for_heredoc(int argc, char **argv, t_storage *info)
{
	if (argc != 6)
		print_error_and_exit("Wrong number of arguments", NULL, -1);
	info->outfile_name = argv[argc - 1];
	if (((access(info->outfile_name, W_OK)) == -1) && errno == EACCES)
		print_error_and_exit(strerror(errno), info->outfile_name, -1);
	info->num_of_cmds = 2;
	info->limiter = argv[2];
	malloc_grandchild_pids(info);
	malloc_pipe_fds(info);
	malloc_cmd_args(info, argv);
}

void	parse_arguments_for_multi_pipes(t_storage *info, int argc, char **argv)
{
	info->infile_name = argv[1];
	info->outfile_name = argv[argc - 1];
	info->num_of_cmds = argc - 3;
	malloc_grandchild_pids(info);
	malloc_pipe_fds(info);
	malloc_cmd_args(info, argv);
}

void	parse_arguments(int argc, char **argv, t_storage *info)
{
	char	*heredoc;

	heredoc = "here_doc";
	if (argc < 5)
		print_error_and_exit("Number of arguments has to be more than 3", \
			NULL, -1);
	if ((!ft_strncmp(argv[1], heredoc, ft_strlen(heredoc))) \
		&& (ft_strlen(argv[1]) == ft_strlen(heredoc)))
	{
		info->heredoc_flag = 1;
		parse_arguments_for_heredoc(argc, argv, info);
		heredoc_to_tmpfile(info);
	}
	else
	{
		info->heredoc_flag = 0;
		parse_arguments_for_multi_pipes(info, argc, argv);
	}
}
