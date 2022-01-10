/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraylist.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:24:23 by gilee             #+#    #+#             */
/*   Updated: 2022/01/10 10:34:05 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAYLIST_H
# define ARRAYLIST_H

# include "../../libft/libft.h"

typedef struct s_ArrayListNodeType
{
	char	*data;
}	t_arraylistnode;

typedef struct s_ArrayListType
{
	int				current_element_count;
	int				max_element_count;
	t_arraylistnode	*p_element;
}	t_arraylist;

/* arraylist.c */
t_arraylist		*create_array_list(int max_element_count);
void			delete_array_list(t_arraylist *pList);
int				add_alelement(t_arraylist *pList,
					int position, t_arraylistnode element);
int				remove_alelement(t_arraylist *pList, int position);
t_arraylistnode	*get_alelement(t_arraylist *pList, int position);
/* array_utils.c */
void			clear_array_list(t_arraylist *pList);
int				get_array_list_length(t_arraylist *pList);
int				is_array_list_full(t_arraylist *pList);

# ifndef _COMMON_LIST_DEF_
#  define _COMMON_LIST_DEF_

#  define TRUE		1
#  define FALSE		0

# endif
#endif
