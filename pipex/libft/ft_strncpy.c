/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:03:30 by sehee             #+#    #+#             */
/*   Updated: 2021/09/26 10:20:03 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strncpy(char *dst, char const *src, size_t src_len)
{
	size_t	i;

	i = 0;
	while (i < src_len)
	{
		dst[i] = src[i];
		i++;
	}
}
