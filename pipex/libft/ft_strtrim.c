/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 20:54:49 by sehhong           #+#    #+#             */
/*   Updated: 2021/09/26 12:58:05 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char const *set, char c)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	non_set_start(char const *s1, char const *set)
{
	int		i;

	i = 0;
	while (is_set(set, s1[i]))
		i++;
	return (i);
}

static int	non_set_end(char const *s1, char const *set)
{
	int		i;
	int		s1_len;

	s1_len = ft_strlen(s1);
	i = 0;
	while (i < s1_len && is_set(set, s1[s1_len - 1 - i]))
		i++;
	return (s1_len - 1 - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*ret;

	if (s1 == NULL)
		return (NULL);
	else if (set == NULL)
		return (ft_strdup(s1));
	start = non_set_start(s1, set);
	end = non_set_end(s1, set);
	if (start > end)
		return (ft_strdup(""));
	ret = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!ret)
		return (0);
	i = 0;
	while (i + start < end + 1)
	{
		ret[i] = s1[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
