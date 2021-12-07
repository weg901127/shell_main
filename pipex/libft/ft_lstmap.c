/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:49:39 by sehhong           #+#    #+#             */
/*   Updated: 2021/09/26 12:47:51 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*curr;
	t_list	*ret_lst;
	t_list	*new_lst;

	if (lst == NULL || f == NULL)
		return (NULL);
	ret_lst = ft_lstnew(f(lst->content));
	if (!ret_lst)
	{
		ft_lstdelone(ret_lst, del);
		return (NULL);
	}
	curr = lst->next;
	while (curr != NULL)
	{
		new_lst = ft_lstnew(f(curr->content));
		if (!new_lst)
		{
			ft_lstclear(&ret_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&ret_lst, new_lst);
		curr = curr->next;
	}
	return (ret_lst);
}
