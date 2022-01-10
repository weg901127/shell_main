/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_runtime_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:55:53 by gilee             #+#    #+#             */
/*   Updated: 2022/01/10 10:55:54 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

void	init_runtime_env(t_storage *bag)
{
	t_arraylistnode	element;

	element.data = ft_strjoin("0=", "microshell");
	add_alelement(bag->runtime_env,
		bag->runtime_env->current_element_count, element);
	element.data = ft_strjoin("?=", "0");
	add_alelement(bag->runtime_env,
		bag->runtime_env->current_element_count, element);
}
