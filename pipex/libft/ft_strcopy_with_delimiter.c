/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcopy_with_delimiter.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 20:02:56 by sehee             #+#    #+#             */
/*   Updated: 2021/09/26 10:16:03 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcopy_with_delimiter(char *dest, char *src, char c)
{
	while (*src != '\0' && *src != c)
		*dest++ = *src++;
	*dest = '\0';
}
