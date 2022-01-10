/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:44:26 by gilee             #+#    #+#             */
/*   Updated: 2022/01/10 10:45:57 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

int	builtin_env(t_storage *bag)
{
	int		i;
	char	*data;

	i = 0;
	while (i < bag->environ->current_element_count)
	{
		data = get_alelement(bag->environ, i)->data;
		ft_putendl_fd(data, STDOUT_FD);
		i++;
	}
	return (EXIT_SUCCESS);
}
