/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_last_redirect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:57:06 by gilee             #+#    #+#             */
/*   Updated: 2022/01/10 10:57:07 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

char	*get_last_redirect(char *str, int target)
{
	char	*buf;
	char	*res;

	res = NULL;
	buf = str;
	while (buf)
	{
		buf = ft_strchr(buf, target);
		if (buf)
		{
			res = buf;
			buf = buf + 1;
		}
	}
	return (res);
}
