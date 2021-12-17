/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_environ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:45:14 by gilee             #+#    #+#             */
/*   Updated: 2021/12/17 13:12:24 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

void	init_environ(t_storage *bag)
{
	extern char		**environ;
	t_ArrayListNode	element;
	int				i;
	char			*cwd;

	i = 0;
	while (environ[i])
	{
		element.data = environ[i];
		addALElement(bag->environ, bag->environ->current_element_count, element);
		i++;
	}
	
	//bash 처음 시작하자마자, echo $_하면 /bin/bash로 뜸.
	cwd = get_value(bag->environ, "PWD");
	getALElement(bag->environ, bag->environ->current_element_count -1)->data = \
		ft_strjoin("_=", ft_strjoin(cwd, "/microshell"));
}
