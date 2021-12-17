/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 01:26:59 by sehhong           #+#    #+#             */
/*   Updated: 2021/12/16 16:09:20 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

//TODO error가 일어날 경우가 언제가 있지? 있을 경우, exit code는?
//아무리 생각해도 실패할 경우가 거의 없는듯....?
//리스트의 형태에 따라 바꿔야 함.
void	builtin_echo(t_storage *bag, char *str, int n_option)
{
	ft_putstr_fd(str, 1);
	if (!n_option)
		write(1, "\n", 1);
	set_env_var(bag, EXIT_SUCCESS);
}