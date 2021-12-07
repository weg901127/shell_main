/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:09:31 by sehee             #+#    #+#             */
/*   Updated: 2021/09/26 13:29:49 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_chunk(char *str, char c)
{
	int	ck_cnt;
	int	str_cnt;

	str_cnt = 0;
	ck_cnt = 0;
	while (*str)
	{
		if (*str != c)
			str_cnt++;
		else
		{
			ck_cnt++;
			str_cnt = 0;
		}
		str++;
	}
	if (str_cnt)
		ck_cnt++;
	return (ck_cnt);
}

static	void	str_input(char *dest, char *src, char c)
{
	while (*src != '\0' && *src != c)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
}

static void	str_malloc_for_non_c(char **str, char c, char **ret, int *ck)
{
	int	i;

	i = 0;
	while ((*str)[i] != '\0' && (*str)[i] != c)
		i++;
	ret[*ck] = (char *)malloc(sizeof(char) * (i + 1));
	if (!ret)
	{
		ft_malloc_fail_str(ret, *ck);
		return ;
	}
	str_input(ret[*ck], *str, c);
	(*ck)++;
	*str += i;
}

static void	str_malloc(char **ret, char *str, char c)
{
	int		ck;

	ck = 0;
	if (*str == c)
	{
		ret[ck] = (char *)malloc(sizeof(char));
		if (!ret)
		{
			ft_malloc_fail_str(ret, ck);
			return ;
		}
		*ret[ck] = '\0';
		ck++;
		str++;
	}
	while (*str)
	{
		if (*str == c)
			str++;
		else
			str_malloc_for_non_c(&str, c, ret, &ck);
	}
}

char	**ft_split(char *str, char c)
{
	char	**ret;
	int		len_chunk;

	if (str == NULL)
		return (NULL);
	len_chunk = count_chunk(str, c);
	ret = (char **)malloc(sizeof(char *) * (len_chunk + 1));
	if (!ret)
		return (NULL);
	ret[len_chunk] = (char *)0;
	str_malloc(ret, str, c);
	return (ret);
}
