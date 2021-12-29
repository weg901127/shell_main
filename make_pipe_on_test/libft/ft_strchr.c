/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 04:44:06 by gilee             #+#    #+#             */
/*   Updated: 2021/12/06 21:06:50 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	len;

	if (s)
	{
		len = ft_strlen(s) + 1;
		while (len--)
		{
			if (*s++ == (char)c)
				return ((char *)--s);
		}
	}
	return (NULL);
}
