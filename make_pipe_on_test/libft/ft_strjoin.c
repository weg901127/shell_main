/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 04:42:29 by gilee             #+#    #+#             */
/*   Updated: 2021/06/30 20:24:06 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned char	*res;
	size_t			s1_len;
	size_t			s2_len;
	size_t			amt;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	amt = s1_len + s2_len;
	res = (unsigned char *)ft_calloc((amt) + 1, sizeof(unsigned char));
	if (!res)
		return (NULL);
	ft_memcpy(res, s1, s1_len);
	ft_memcpy(res + s1_len, s2, s2_len);
	*(res + s1_len + s2_len) = '\0';
	return ((char *)(res));
}
/*
** Parameters----------------------------------------------
**	#1. The prefix string.
**	#2. The suffix string.
*/
