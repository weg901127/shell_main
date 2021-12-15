/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_exit_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:35:25 by sehhong           #+#    #+#             */
/*   Updated: 2021/12/15 16:07:56 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

//runtime_env의 요소중 $0, $?를 정해진 위치에 두면 좋을 듯.
void	set_exit_status(t_storage *bag, int exit_status)
{
	getALElement(bag->runtime_env->pElement, 1)->data = ft_itoa(exit_status);
}
