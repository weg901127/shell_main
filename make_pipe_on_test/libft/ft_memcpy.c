/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 04:52:55 by gilee             #+#    #+#             */
/*   Updated: 2020/12/28 06:57:18 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *d, void const *s, size_t n)
{
	char			*pd;
	char const		*ps;

	pd = d;
	ps = s;
	if (n == 0)
		return (d);
	if ((ps == NULL) && (pd == NULL))
		return (NULL);
	if ((ps != NULL) || (pd != NULL))
	{
		while (n--)
			*pd++ = *ps++;
	}
	return (d);
}
