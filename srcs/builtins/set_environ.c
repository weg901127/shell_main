/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_environ.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:49:02 by gilee             #+#    #+#             */
/*   Updated: 2022/01/10 10:49:08 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

void	set_environ(t_storage *bag, int exit_status)
{
	char	*data;
	char	*buf;

	data = get_alelement(bag->runtime_env, 1)->data;
	free(data);
	data = NULL;
	buf = ft_itoa(exit_status);
	(get_alelement(bag->runtime_env, 1)->data) = ft_strjoin("?=", buf);
	free(buf);
	buf = NULL;
}
