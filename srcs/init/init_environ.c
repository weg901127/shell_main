/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_environ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:45:14 by gilee             #+#    #+#             */
/*   Updated: 2021/12/09 14:18:03 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

void	init_environ(t_storage *bag)
{
	extern char		**environ;
	t_ArrayListNode	element;
	int				i;

	i = 0;
	while (environ[i])
	{
		element.data = environ[i];
		addALElement(bag->environ, 0, element);
		i++;
	}
}
