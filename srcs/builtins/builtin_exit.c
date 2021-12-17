/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 01:45:33 by sehhong           #+#    #+#             */
/*   Updated: 2021/12/16 16:11:06 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

void    builtin_exit(int is_only_cmd)
{
    //유일한 명령어 일 경우만 bash를 나감. (예: exit, exit 5)
    if (is_only_cmd)
    {
	    //환경변수 ?를 바꾸는 함수 -> 필요없음.
        //exit전에 필요한 처리들.
        ft_putendl_fd("exit", 1);
        //if (리스트에 exit만 있을 경우)
        //exit(EXIT_SUCCESS);
        //else if (리스트에 {"exit", "10", 0})
        //exit(ft_atoi(10));
        //else (리스트에 3개 이상의 값이 있을 때)
        //예: exit 1 2 3 => exit\nbash: exit: too many arguments\n (bash 안끝남.)
        //{
            //ft_print_error("exit", NULL, "too many arguments");
            //$? : 1로 변경
            ///$_: 안변함.
        //}
    }
    else    //유일한 명령어가 아닐 경우 bash 안꺼짐.
    {
        //if (리스트에 exit만 있을 경우)
        //set_env_var(bag, EXIT_SUCCESS);
        //else if (리스트에 {"exit", "10", 0})
        //set_env_var(bag, ft_atoi("10"));
        //else (리스트에 3개 이상의 값이 있을 때)
        //{
            //ft_print_error("exit", NULL, "too many arguments");
            //set_env_var(bag, EXIT_FAILURE);
        //}   
    }
}