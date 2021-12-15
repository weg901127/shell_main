/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 01:45:33 by sehhong           #+#    #+#             */
/*   Updated: 2021/12/15 02:06:44 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

//exit 56: 이럴 경우 어떡하지? 처리해야 하나?
//exit | ls | echo "hi" : bash 계속 유지 without "exit"
void    builtin_exit(int is_lastcmd)
{
    if (is_lastcmd)
    {
	    //환경변수 ?를 바꾸는 함수
        ft_putendl_fd("exit", 1);
        exit(0);
    }
}