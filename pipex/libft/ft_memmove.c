/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 16:23:38 by sehhong           #+#    #+#             */
/*   Updated: 2021/05/17 15:48:53 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (0);
	i = 0;
	if (dst < src)
		ft_memcpy(d, s, len);
	else
	{
		while (len >= i + 1)
		{
			d[len - 1 - i] = s[len - 1 - i];
			i++;
		}
	}
	return (dst);
}
