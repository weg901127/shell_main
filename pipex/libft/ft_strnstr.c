/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:39:00 by sehhong           #+#    #+#             */
/*   Updated: 2021/09/26 12:56:28 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hs, const char *nd, size_t len)
{
	size_t	i;
	size_t	cmp_len;
	size_t	nd_len;

	i = 0;
	if (nd[i] == '\0')
		return ((char *)hs);
	nd_len = ft_strlen(nd);
	while (hs[i] && i < len)
	{
		if (len > nd_len + i)
			cmp_len = nd_len;
		else
			cmp_len = len - i;
		if (hs[i] == nd[0] && (len >= ft_strlen(nd) + i)
			&& ft_strncmp(hs + i, nd, cmp_len) == 0)
			return ((char *)hs + i);
		else
			i++;
	}
	return (0);
}
