/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 03:36:47 by gilee             #+#    #+#             */
/*   Updated: 2021/06/30 20:38:55 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned char	*res;
	unsigned char	*pres;
	unsigned char	*ps;

	if (ft_strlen(s) <= start)
		len = 0;
	res = (unsigned char *)ft_calloc(len + 1, sizeof(unsigned char));
	if (!res)
		return (NULL);
	pres = res;
	ps = ((unsigned char *)(s + start));
	while (len--)
	{
		*pres++ = *ps++;
	}
	*pres = '\0';
	return ((char *)res);
}
/*
** Parameters----------------------------------------------
** #1. The string from which to create the substring.
** #2. The start index of the substring in the string ’s’.
** #3. The maximum length of the substring.
*/
