/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 00:56:10 by hongsehui         #+#    #+#             */
/*   Updated: 2021/12/15 01:50:14 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

//환경변수 $? 변경 필요함.

int	builtin_cd(char *path)
{
	if (chdir(path) == -1)
	{	
        ft_print_error("cd", path, strerror(errno));
        //환경변수 ?를 바꾸는 함수
        return (-1);
    }
    //환경변수 ?를 바꾸는 함수
    return (0);
}
