/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 19:02:12 by gilee             #+#    #+#             */
/*   Updated: 2021/02/26 19:02:15 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/get_next_line.h"

char	*ft_strdup2(const char *s1)
{
	char		*rest;
	const char	*ps1;
	size_t		len;

	if (!s1)
	{
		rest = (char *)malloc((1) * sizeof(char));
		if (!rest)
			return (NULL);
		rest[0] = '\0';
		return (rest);
	}
	ps1 = s1;
	len = ft_strlen(s1);
	rest = (char *)malloc((len + 1) * sizeof(char));
	if (!rest)
		return (NULL);
	while (len--)
	{
		*rest++ = *ps1++;
	}
	*rest = '\0';
	return (rest - ft_strlen(s1));
}
