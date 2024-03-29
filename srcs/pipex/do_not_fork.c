/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_not_fork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:56:56 by gilee             #+#    #+#             */
/*   Updated: 2022/01/10 10:56:56 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

static int	is_special(char **str)
{
	int	res;

	res = 0;
	res |= (ft_strlen(str[0]) == 6
			&& !ft_strncmp(str[0], "export", 6)
			&& !(ft_strchr(str[1], '<') || ft_strchr(str[1], '>')));
	res |= (ft_strlen(str[0]) == 3
			&& !ft_strncmp(str[0], "env", 3)
			&& !(ft_strchr(str[1], '<') || ft_strchr(str[1], '>')));
	res |= (ft_strlen(str[0]) == 5 && !ft_strncmp(str[0], "unset", 5));
	res |= (ft_strlen(str[0]) == 4 && !ft_strncmp(str[0], "exit", 4));
	res |= (ft_strlen(str[0]) == 2 && !ft_strncmp(str[0], "cd", 2));
	return (res);
}

int	do_not_fork(t_storage *bag, char *str)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(str, ' ');
	if (bag->num_of_cmds == 1 && is_special(split))
	{
		while (split[i])
			free(split[i++]);
		free(split);
		return (1);
	}
	while (split[i])
		free(split[i++]);
	free(split);
	return (0);
}
