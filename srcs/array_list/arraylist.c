/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraylist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:32:51 by gilee             #+#    #+#             */
/*   Updated: 2022/01/10 10:32:52 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arraylist.h"

t_arraylist	*create_array_list(int max_element_count)
{
	t_arraylist	*tmp;

	tmp = (t_arraylist *)ft_calloc(1, sizeof(t_arraylist));
	tmp->max_element_count = max_element_count;
	tmp->current_element_count = 0;
	tmp->p_element = (t_arraylistnode *)ft_calloc
		(max_element_count, sizeof(t_arraylistnode));
	return (tmp);
}

void	delete_array_list(t_arraylist *pList)
{
	free(pList->p_element);
	free(pList);
	pList = NULL;
}

int	add_alelement(t_arraylist *pList, int position, t_arraylistnode element)
{
	t_arraylistnode	*tmp;

	if (is_array_list_full(pList))
	{
		pList->max_element_count *= 3;
		tmp = (t_arraylistnode *)ft_calloc(pList->max_element_count,
				sizeof(t_arraylistnode));
		ft_memcpy(tmp, pList->p_element,
			pList->current_element_count * sizeof(t_arraylistnode));
		free(pList->p_element);
		pList->p_element = tmp;
	}
	if ((pList->current_element_count
			&& position > pList->current_element_count))
		return (FALSE);
	ft_memmove(pList->p_element + position + 1, pList->p_element + position,
		sizeof(t_arraylistnode) * (pList->current_element_count - position));
	*(pList->p_element + position) = element;
	(pList->current_element_count)++;
	return (TRUE);
}

int	remove_alelement(t_arraylist *pList, int position)
{
	if (position >= pList->current_element_count
		|| pList->current_element_count == 0)
		return (FALSE);
	ft_memmove(pList->p_element + position, pList->p_element + position + 1,
		sizeof(t_arraylistnode) * (pList->current_element_count - position));
	(pList->current_element_count)--;
	return (TRUE);
}

t_arraylistnode	*get_alelement(t_arraylist *pList, int position)
{
	if (position < pList->max_element_count)
		return (pList->p_element + position);
	return (NULL);
}
