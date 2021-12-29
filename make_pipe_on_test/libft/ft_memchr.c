/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 04:52:35 by gilee             #+#    #+#             */
/*   Updated: 2021/06/30 20:14:42 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*ps;

	ps = s;
	while (n--)
	{
		if (*ps++ == (unsigned char)c)
			return ((unsigned char *)(--ps));
	}
	return (NULL);
}
