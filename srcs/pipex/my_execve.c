/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:57:27 by gilee             #+#    #+#             */
/*   Updated: 2022/01/10 10:57:28 by gilee            ###   ########.fr       */
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

void	my_execve(t_storage *bag, char	*str)
{
	char	**argv;
	char	**buf;
	int		i;
	int		j;

	i = 0;
	j = 0;
	argv = set_argv(bag, str);
	buf = (char **)ft_calloc(ft_splitcnt(argv) + 1, sizeof(char *));
	while (argv[i])
	{
		if (ft_strchr(argv[i], '<') || ft_strchr(argv[i], '>'))
		{
			free(argv[i]);
			argv[i++] = NULL;
			continue ;
		}
		buf[j] = argv[i];
		i++;
		j++;
	}
	if (is_builtin(bag, buf[0]))
		exit(execve_builtin(bag, str));
	execve(buf[0], buf, get_environ(bag));
	exit(EXIT_FAILURE);
}
