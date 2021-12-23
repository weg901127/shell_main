/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 05:47:38 by gilee             #+#    #+#             */
/*   Updated: 2021/06/30 20:38:11 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_fr(char const *s1, char const *set)
{
	size_t				count;
	unsigned char		*ps1;
	unsigned const char	*pset;

	count = 0;
	ps1 = (unsigned char *)s1;
	pset = (unsigned char *)set;
	while (*pset != '\0')
	{
		if (*ps1 == *pset++)
		{
			ps1++;
			pset = (unsigned char *)set;
			count++;
		}
	}
	return (count);
}

static size_t	ft_bk(char const *s1, char const *set)
{
	size_t				count;
	unsigned char		*ps1;
	unsigned char		*pset;

	count = 0;
	ps1 = (unsigned char *)s1;
	pset = (unsigned char *)set;
	while (*pset != '\0')
	{
		if (*ps1 == *pset++)
		{
			ps1--;
			pset = (unsigned char *)set;
			count++;
		}
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned char		*ps1;
	size_t				reslen;
	size_t				frlen;
	size_t				bklen;

	ps1 = (unsigned char *)s1;
	reslen = ft_strlen(s1);
	frlen = ft_fr(s1, set);
	if (reslen == frlen)
	{
		ps1 = (unsigned char *)ft_calloc(1, sizeof(char));
		if (!ps1)
			return (NULL);
		return ((char *)ps1);
	}
	bklen = ft_bk(s1 + reslen - 1, set);
	reslen -= (frlen + bklen);
	ps1 += frlen;
	return ((char *)ft_substr((char const *)ps1, 0, reslen));
}
/*
** Parameters----------------------------------------------
**	#1. The string to be trimmed.
**	#2. The reference set of characters to trim.
*/
