/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:55:39 by gilee             #+#    #+#             */
/*   Updated: 2022/01/10 10:55:39 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

void	init_builtin(t_storage *bag)
{
	int				fd;
	char			*buf;
	t_arraylistnode	element;

	fd = open("./.builtin", O_RDONLY);
	while (1)
	{
		get_next_line(fd, &buf);
		element.data = buf;
		if (*buf == 0)
		{	
			free(buf);
			buf = NULL;
			break ;
		}
		add_alelement(bag->builtin, 0, element);
	}
	close(fd);
}
