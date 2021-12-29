/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 04:49:19 by gilee             #+#    #+#             */
/*   Updated: 2020/12/28 21:33:59 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		res;
	size_t		len;

	res = ft_strlen(src);
	if (dstsize)
	{
		if (res >= dstsize)
			len = dstsize - 1;
		else
			len = res;
		ft_memcpy(dst, src, len);
		*(dst + len) = '\0';
	}
	return (res);
}
