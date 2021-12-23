/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 12:55:11 by gilee             #+#    #+#             */
/*   Updated: 2021/06/30 20:53:56 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	allfree(char **res, int i)
{
	while (i)
		free(res[--i]);
	free(res);
}

static size_t	ft_getdeli(char const *s, char c)
{
	char	*ps;
	size_t	count;

	count = 0;
	ps = (char *)s;
	if (*ps == 0)
		return (0);
	while (*ps)
	{
		if ((*ps != c && *(ps + 1) == c) || *(ps + 1) == '\0')
			count++;
		ps++;
	}
	if (*(ps - 1) == c)
		count--;
	return (count);
}

static char	**ft_setsrc(size_t len)
{
	char	**res;
	int		flag;

	flag = 1;
	if (len != 1)
		flag = 2;
	if (len == 0)
	{
		res = ft_calloc(1, sizeof(char *));
		if (!res)
			return (NULL);
		return (res);
	}
	res = ft_calloc(len + flag, sizeof(char *));
	if (!res)
		return (NULL);
	return (res);
}

static char	*ft_setstr(char **s, char c)
{
	size_t	count;
	char	*ps;
	char	*res;

	ps = *s;
	count = 0;
	while (**s != c && **s != '\0')
	{
		count++;
		*s += 1;
	}
	res = (char *)ft_calloc(count + 1, sizeof(char));
	if (!res)
		return (NULL);
	return (ft_memcpy(res, ps, count));
}

char	**ft_split(char const *s, char c)
{
	char			**res;
	char			*ps;
	int				i;

	ps = (char *)s;
	i = 0;
	res = ft_setsrc(ft_getdeli(s, c));
	if (!res)
		return (NULL);
	while (*ps)
	{
		if (*ps != c)
		{
			res[i] = ft_setstr(&ps, c);
			if (!res[i++])
			{
				allfree(res, i);
				return (NULL);
			}
			if (*ps == 0)
				--ps;
		}
		ps++;
	}
	return (res);
}
/*
** Parameters----------------------------------------------
**	#1. The string to be split.
**	#2. The delimiter character.
*/
