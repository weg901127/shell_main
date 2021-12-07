/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 08:51:14 by sehhong           #+#    #+#             */
/*   Updated: 2021/05/08 15:03:03 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	d_len;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	d_len = ft_strlen(dst);
	if (dstsize <= d_len)
		return (ft_strlen(src) + dstsize);
	while (src[i] && i + d_len + 1 < dstsize)
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (d_len + ft_strlen(src));
}
