/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 04:50:04 by gilee             #+#    #+#             */
/*   Updated: 2021/06/30 20:33:57 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned const char	*ps1;
	unsigned const char	*ps2;

	ps1 = (unsigned const char *)s1;
	ps2 = (unsigned const char *)s2;
	while (n--)
	{
		if (*ps1++ != *ps2++)
			return ((int)(*--ps1 - *--ps2));
		if (*(ps1 - 1) == '\0')
			return (0);
	}
	return (0);
}
