/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:54:57 by sehhong           #+#    #+#             */
/*   Updated: 2021/09/26 12:48:05 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_ele;

	new_ele = malloc(sizeof(t_list));
	if (!new_ele)
		return (0);
	new_ele->content = content;
	new_ele->next = NULL;
	return (new_ele);
}
