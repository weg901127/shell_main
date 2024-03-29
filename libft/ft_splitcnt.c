/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitcnt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:34:02 by gilee             #+#    #+#             */
/*   Updated: 2022/01/10 10:58:54 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_splitcnt(char **src)
{
	int	cnt;

	cnt = 0;
	if (src == NULL || *src == NULL)
		return (0);
	while (src[cnt])
		cnt++;
	return (cnt);
}
