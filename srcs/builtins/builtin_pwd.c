/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 00:56:06 by hongsehui         #+#    #+#             */
/*   Updated: 2021/12/15 01:51:33 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

int	builtin_pwd(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		ft_print_error("pwd", NULL, strerror(errno));
		//환경변수 ?를 바꾸는 함수
		return (-1);
	}
	ft_putendl_fd(pwd, 1);
	pwd = NULL;
	free(pwd);
    //환경변수 ?를 바꾸는 함수
    return (0);
}
