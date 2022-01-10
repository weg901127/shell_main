/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:26:01 by gilee             #+#    #+#             */
/*   Updated: 2022/01/10 10:26:35 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arraylist.h"

void	clear_array_list(t_arraylist *pList)
{
	free(pList->p_element);
	pList->p_element = NULL;
	pList->current_element_count = 0;
}

int	get_array_list_length(t_arraylist *pList)
{
	return (pList->current_element_count);
}

int	is_array_list_full(t_arraylist *pList)
{
	return (pList->max_element_count == pList->current_element_count);
}
