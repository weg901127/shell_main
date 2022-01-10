/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:57:27 by gilee             #+#    #+#             */
/*   Updated: 2022/01/10 15:54:15 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

static char	**set_argv(t_storage *bag, char *str)
{
	char	**tmp;
	char	*cmd_tmp;
	int		target;

	target = 0;
	tmp = ft_split(str, ' ');
	while (ft_strchr(tmp[target], '<') || ft_strchr(tmp[target], '>'))
		target++;
	if (!ft_strchr(tmp[target], '/') && !is_builtin(bag, tmp[target]))
	{
		cmd_tmp = my_which(bag, tmp[target]);
		if (!cmd_tmp)
			exit(127);
		free(tmp[target]);
		tmp[target] = cmd_tmp;
	}
	return (tmp);
}

static void	my_execve_core(char **argv, char **buf, int *i, int *j)
{
	while (argv[*i])
	{
		if (ft_strchr(argv[*i], '<') || ft_strchr(argv[*i], '>'))
		{
			free(argv[*i]);
			argv[(*i)++] = NULL;
			continue ;
		}
		buf[*j] = argv[*i];
		(*i)++;
		(*j)++;
	}
}

void	my_execve(t_storage *bag, char	*str)
{
	char			**argv;
	char			**buf;
	char			*tmp[2];
	static int		i;
	static int		j;

	tmp[0] = cutnjoin(str, '\'');
	tmp[1] = cutnjoin(tmp[0], '\"');
	argv = set_argv(bag, tmp[1]);
	buf = (char **)ft_calloc(ft_splitcnt(argv) + 1, sizeof(char *));
	my_execve_core(argv, buf, &i, &j);
	if (is_builtin(bag, buf[0]))
		exit(execve_builtin(bag, str));
	execve(buf[0], buf, get_environ(bag));
	exit(EXIT_FAILURE);
}
