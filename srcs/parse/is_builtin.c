/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:36:40 by gilee             #+#    #+#             */
/*   Updated: 2021/12/08 14:38:57 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

bool	is_builtin(t_storage *bag, const char *cmd)
{
	bool	res;
	int		i;
	char	*tmp;

	res = false;
	i = bag->builtin->currentElementCount;
	while (i--)
	{
		tmp = getALElement(bag->builtin, i)->data;
		if (!ft_strncmp(cmd, tmp, ft_strlen(tmp)))
			res = true;
	}
	return (res);
}
