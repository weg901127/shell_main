/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:12:15 by sehhong           #+#    #+#             */
/*   Updated: 2021/09/26 12:48:15 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		lst_cnt;
	t_list	*curr;

	curr = lst;
	lst_cnt = 0;
	while (curr != NULL)
	{
		lst_cnt++;
		curr = curr->next;
	}
	return (lst_cnt);
}
