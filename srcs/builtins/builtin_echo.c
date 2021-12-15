/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 01:26:59 by sehhong           #+#    #+#             */
/*   Updated: 2021/12/15 16:56:18 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

//TODO error가 일어날 경우가 언제가 있지? 있을 경우, exit code는?
bool	builtin_echo(t_storage *bag, char *str, int n_option)
{
	ft_putstr_fd(str, 1);
	if (!n_option)
		write(1, "\n", 1);
	set_exit_status(bag, EXIT)
}