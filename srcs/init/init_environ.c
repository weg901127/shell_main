/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_environ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:45:14 by gilee             #+#    #+#             */
/*   Updated: 2021/12/16 17:05:52 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

void	init_environ(t_storage *bag)
{
	extern char		**environ;
	t_ArrayListNode	element;
	int				i;
	//char			*cwd;

	i = 0;
	while (environ[i])
	{
		element.data = environ[i];
		addALElement(bag->environ, bag->environ->current_element_count, element);
		i++;
	}
	//bash 처음 시작하자마, echo $_하면 /bin/bash로 뜸.
	//cwd = getcwd(NULL, 0);
	//getALElement(bag->environ, bag->environ->current_element_count -1)->data = getcwd(NULL, 0);
}
