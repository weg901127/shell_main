/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:48:53 by gilee             #+#    #+#             */
/*   Updated: 2022/01/10 10:48:55 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

char	*get_value(t_arraylist *env, char *str)
{
	int		i;
	int		len_str;
	char	*data;

	i = 0;
	len_str = ft_strlen(str);
	if (!str)
		return (NULL);
	while (i < env->current_element_count)
	{
		data = get_alelement(env, i)->data;
		if (strncmp_exact(data, str, '='))
			return (data + len_str + 1);
		i++;
	}
	return (NULL);
}
