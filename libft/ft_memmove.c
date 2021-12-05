/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 04:43:43 by gilee             #+#    #+#             */
/*   Updated: 2021/01/21 03:38:52 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char			*tmp;
	const unsigned char		*ps;

	tmp = dst;
	ps = src;
	if (len == 0)
		return (dst);
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst <= src)
	{
		while (len--)
			*tmp++ = *ps++;
	}
	else
	{
		tmp += len;
		ps += len;
		while (len--)
			*--tmp = *--ps;
	}
	return (dst);
}
