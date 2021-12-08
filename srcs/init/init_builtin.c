/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:34:34 by gilee             #+#    #+#             */
/*   Updated: 2021/12/08 14:39:47 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

void	init_builtin(t_storage *bag)
{
	int				fd;
	char			*buf;
	t_ArrayListNode	element;

	fd = open("./.builtin", O_RDONLY);
	while (1)
	{
		get_next_line(fd, &buf);
		element.data = buf;
		if(*buf == 0)
			break;
		addALElement(bag->builtin, 0, element);
	}
}
