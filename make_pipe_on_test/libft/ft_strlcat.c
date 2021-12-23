/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 04:53:36 by gilee             #+#    #+#             */
/*   Updated: 2021/06/30 20:25:03 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	lens;
	size_t	i;

	i = 0;
	lens = ft_strlen(src);
	if (!size)
		return (lens);
	while (*dest && size)
	{
		dest++;
		i++;
		size--;
	}
	while (*src && size > 1)
	{
		*dest++ = *src++;
		size--;
	}
	if (size != 0)
	{
		*dest = '\0';
	}
	return (lens + i);
}
