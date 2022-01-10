/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_environ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:55:43 by gilee             #+#    #+#             */
/*   Updated: 2022/01/10 10:55:44 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

static char	*cpy_environ(char *str)
{
	char	*ret;
	int		len_str;

	len_str = ft_strlen(str);
	if (str == NULL)
		return (NULL);
	ret = (char *)ft_calloc(len_str + 1, sizeof(char));
	ft_memcpy(ret, str, len_str);
	return (ret);
}

void	init_environ(t_storage *bag)
{
	extern char		**environ;
	t_arraylistnode	element;
	int				i;

	i = 0;
	while (environ[i])
	{
		if (!strncmp_exact(environ[i], "OLDPWD", '=')
			&& !strncmp_exact(environ[i], "_", '='))
		{
			element.data = cpy_environ(environ[i]);
			add_alelement(bag->environ,
				bag->environ->current_element_count, element);
		}
		i++;
	}
}
