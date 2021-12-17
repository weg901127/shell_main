/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:35:25 by sehhong           #+#    #+#             */
/*   Updated: 2021/12/16 16:19:53 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

//runtime_env의 요소중 $0, $?를 정해진 위치에 두면 좋을 듯.
void	set_env_var(t_storage *bag, int exit_status)
{
	//t_ArrayListNode	element;
	//$?의 고정된 위치에 따라 position(1)을 바꿀 것!
	getALElement(bag->runtime_env, 1)->data = ft_itoa(exit_status);

	//$_의 값도 바꿔줘야함. 매개변수 추가 필요 + environ에서 _의 위치 고정해주자.
	//free(getALElement(bag->environ->p_element, 0)->data);
	//getALElement(bag->environ->p_element, 0)->data = ft_strjoin("_=", 마지막인자);
}
