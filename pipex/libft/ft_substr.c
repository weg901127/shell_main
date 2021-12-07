/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 11:05:38 by sehhong           #+#    #+#             */
/*   Updated: 2021/09/26 13:42:38 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (i >= ft_strlen(src))
			dst[i] = '\0';
		else
			dst[i] = src[i];
		i++;
	}
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	max_len;
	size_t	final_len;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
		final_len = 0;
	else
	{
		max_len = ft_strlen(s) - start;
		if (max_len >= len)
			final_len = len;
		else
			final_len = max_len;
	}
	ret = (char *)malloc(sizeof(char) * (final_len + 1));
	if (!ret)
		return (0);
	strncpy(ret, s + start, final_len);
	ret[final_len] = '\0';
	return (ret);
}
