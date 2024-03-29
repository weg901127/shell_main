/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:55:34 by gilee             #+#    #+#             */
/*   Updated: 2022/01/10 10:55:35 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

void	init_bag(t_storage *bag)
{
	bag->builtin = create_array_list(7);
	bag->environ = create_array_list(30);
	bag->runtime_env = create_array_list(30);
	bag->last_exit_status = EXIT_SUCCESS;
}
