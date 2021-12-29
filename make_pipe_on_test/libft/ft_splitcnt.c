/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitcnt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:34:02 by gilee             #+#    #+#             */
/*   Updated: 2021/12/20 16:34:31 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_splitcnt(char **src)
{
	int	cnt;

	cnt = 0;
	if (src == NULL || *src == NULL)
		return (0);
	while(src[cnt][0])
		cnt++;
	return (cnt);
}
