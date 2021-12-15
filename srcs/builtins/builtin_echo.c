/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 01:26:59 by sehhong           #+#    #+#             */
/*   Updated: 2021/12/15 16:12:48 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

void	builtin_echo(char *str, int n_option)
{
	ft_putstr_fd(str, 1);
	if (!n_option)
		write(1, "\n", 1);
	//환경변수 ?를 바꾸는 함수
}