/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:56:18 by gilee             #+#    #+#             */
/*   Updated: 2022/01/10 10:56:18 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

bool	is_builtin(t_storage *bag, const char *cmd)
{
	bool	res;
	int		i;
	char	*tmp;

	res = false;
	i = bag->builtin->current_element_count;
	while (i--)
	{
		tmp = get_alelement(bag->builtin, i)->data;
		if (!ft_strncmp(cmd, tmp, ft_strlen(tmp)))
			res = true;
	}
	return (res);
}
