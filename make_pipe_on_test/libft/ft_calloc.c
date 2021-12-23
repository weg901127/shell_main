/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 07:12:56 by gilee             #+#    #+#             */
/*   Updated: 2021/06/30 19:56:50 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*rest;

	rest = (void *)malloc(count * size);
	if (!rest)
		return (NULL);
	ft_memset(rest, 0, (count * size));
	return (rest);
}
