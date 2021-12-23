/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcopy_with_delimiter.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:54:44 by gilee             #+#    #+#             */
/*   Updated: 2021/12/08 13:54:47 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcopy_with_delimiter(char *dest, char *src, char c)
{
	while (*src != '\0' && *src != c)
		*dest++ = *src++;
	*dest = '\0';
}
