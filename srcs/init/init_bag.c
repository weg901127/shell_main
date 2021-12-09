/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:33:30 by gilee             #+#    #+#             */
/*   Updated: 2021/12/09 13:44:52 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

void	init_bag(t_storage *bag)
{
	bag->builtin = createArrayList(7);
	bag->environ = createArrayList(30);
}
