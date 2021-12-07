/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:28:45 by sehhong           #+#    #+#             */
/*   Updated: 2021/09/27 02:55:42 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parse_arguments(t_storage *info, int argc, char **argv)
{
	if (argc != 5)
		print_error_and_exit("Wrong number of arguments", NULL, -1);
	info->infile_name = argv[INFILE_INDEX];
	info->outfile_name = argv[OUTFILE_INDEX];
	info->cmd1_arg = split_cmd(argv[COMMAND1_INDEX]);
	info->cmd2_arg = split_cmd(argv[COMMAND2_INDEX]);
}
