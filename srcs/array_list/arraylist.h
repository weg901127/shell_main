/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraylist.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 01:38:40 by gilee             #+#    #+#             */
/*   Updated: 2021/12/15 17:02:10 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAYLIST_H
# define ARRAYLIST_H

# include "../../libft/libft.h"

typedef struct s_ArrayListNodeType
{
	char	*data;
}	t_ArrayListNode;

typedef struct s_ArrayListType
{
	int				current_element_count;
	int				max_element_count;
	t_ArrayListNode	*p_element;
}	t_ArrayList;

/* arraylist.c */
t_ArrayList		*createArrayList(int max_element_count);
void			deleteArrayList(t_ArrayList *pList);
int				addALElement(t_ArrayList *pList,
					int position, t_ArrayListNode element);
int				removeALElement(t_ArrayList *pList, int position);
t_ArrayListNode	*getALElement(t_ArrayList *pList, int position);
/* array_utils.c */
void			clearArrayList(t_ArrayList *pList);
int				getArrayListLength(t_ArrayList *pList);
int				isArrayListFull(t_ArrayList *pList);

# ifndef _COMMON_LIST_DEF_
#  define _COMMON_LIST_DEF_

#  define TRUE		1
#  define FALSE		0

# endif
#endif
