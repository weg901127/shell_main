/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 04:54:11 by gilee             #+#    #+#             */
/*   Updated: 2021/06/30 20:34:37 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	nlen;

	nlen = ft_strlen(needle);
	if (*needle == '\0')
		return ((char *)(haystack));
	while (*haystack != '\0' && len-- >= nlen)
	{
		if (*haystack == *needle && ft_strncmp(haystack, needle, nlen) == 0)
			return ((char *)(haystack));
		haystack++;
	}
	return (NULL);
}
