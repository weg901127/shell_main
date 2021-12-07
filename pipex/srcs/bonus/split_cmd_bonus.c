/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:56:55 by sehee             #+#    #+#             */
/*   Updated: 2021/09/26 10:22:52 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	define_quote_flag(t_chunk_info *chunk_info, char c)
{
	if (c == '\'')
	{
		if (chunk_info->quote_flag == 0)
			chunk_info->quote_flag++;
		else if (chunk_info->quote_flag == 1)
			chunk_info->quote_flag--;
	}
	else if (c == '"')
	{
		if (chunk_info->quote_flag == 0)
			chunk_info->quote_flag = 2;
		else if (chunk_info->quote_flag == 1)
			chunk_info->str_count++;
		else if (chunk_info->quote_flag == 2)
			chunk_info->quote_flag = 0;
	}
}

static int	chunk_count(char *str, t_chunk_info *chunk_info)
{
	ft_memset(chunk_info, 0, sizeof(*chunk_info));
	while (*str)
	{
		if (*str == '\'' || *str == '"')
			define_quote_flag(chunk_info, *str);
		else if (*str == ' ')
		{
			if (!chunk_info->quote_flag && chunk_info->str_count)
			{
				chunk_info->chunk_count++;
				chunk_info->str_count = 0;
			}
			else if (chunk_info->quote_flag)
				chunk_info->str_count++;
		}
		else
			chunk_info->str_count++;
		str++;
	}
	if (chunk_info->str_count)
		chunk_info->chunk_count++;
	return (chunk_info->chunk_count);
}

static char	*str_input(t_chunk_info *info, char *str, int str_len, \
	char **cmd_arg)
{
	cmd_arg[info->chunk_count] = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!cmd_arg)
	{
		ft_malloc_fail_str(cmd_arg, info->chunk_count);
		print_error_and_exit("malloc() has failed", NULL, -1);
	}
	ft_strcopy_with_delimiter(cmd_arg[info->chunk_count], str, info->delimiter);
	info->chunk_count++;
	if (info->delimiter == ' ')
		str += str_len;
	else
		str += (str_len + 1);
	return (str);
}

static void	delimiter_based_str_input(char **cmd_arg, char *str, t_chunk_info \
	*chunk_info)
{
	int				i;

	ft_memset(chunk_info, 0, sizeof(*chunk_info));
	while (*str)
	{
		if (*str == ' ')
			str++;
		else
		{
			i = 0;
			if (str[i] != '\'' && str[i] != '"')
				chunk_info->delimiter = ' ';
			else
			{
				chunk_info->delimiter = str[i];
				str++;
			}
			while (str[i] != '\0' && str[i] != chunk_info->delimiter)
				i++;
			str = str_input(chunk_info, str, i, cmd_arg);
		}
	}
}

char	**split_cmd(char *str)
{
	char			**cmd_argv;
	int				len_chunk;
	t_chunk_info	chunk_info;

	if (str == NULL)
		return (NULL);
	len_chunk = chunk_count(str, &chunk_info);
	cmd_argv = (char **)malloc(sizeof(char *) * (len_chunk + 1));
	if (!cmd_argv)
		return (NULL);
	cmd_argv[len_chunk] = 0;
	delimiter_based_str_input(cmd_argv, str, &chunk_info);
	return (cmd_argv);
}
