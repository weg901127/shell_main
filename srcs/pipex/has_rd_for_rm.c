/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_rd_for_rm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:50:15 by gilee             #+#    #+#             */
/*   Updated: 2022/01/10 14:50:25 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

int	has_rd_for_rm(char	*str)
{
	int	flag[2];
	int	direction[2];
	int	*zn_s;
	int	*zn_d;
	int	res;

	ft_bzero(flag, sizeof(int) * 2);
	ft_bzero(direction, sizeof(int) * 2);
	init_zone(&zn_s, &zn_d, &str);
	direction[0] = ft_strchr(str, '<') - str;
	direction[1] = ft_strchr(str, '>') - str;
	if (ft_strchr(str, '<'))
		flag[0] = 1;
	if (ft_strchr(str, '>'))
		flag[1] = 1;
	res = (((flag[0] && (!zn_s[direction[0]] || zn_d[direction[0]]))
				&& (flag[0] && (zn_s[direction[0]] || !zn_d[direction[0]])))
			|| ((flag[1] && (!zn_s[direction[1]] || zn_d[direction[1]]))
				&& (flag[1] && (zn_s[direction[1]] || !zn_d[direction[1]]))));
	free(zn_s);
	free(zn_d);
	return (res);
}
