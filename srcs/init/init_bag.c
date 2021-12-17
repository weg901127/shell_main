/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:33:30 by gilee             #+#    #+#             */
/*   Updated: 2021/12/15 16:35:55 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

void	init_bag(t_storage *bag)
{
	bag->builtin = createArrayList(7);
	bag->environ = createArrayList(30);
	bag->runtime_env = createArrayList(30);
}
