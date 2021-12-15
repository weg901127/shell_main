/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 00:24:03 by hongsehui         #+#    #+#             */
/*   Updated: 2021/12/15 12:20:27 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_error(char *cmd, char *str, char *error_str)
{
	ft_putstr_fd("microshell: ", 2);
	ft_putstr_fd(cmd, 2);
	if (str != NULL)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(str, 2);
	}
	if (error_str != NULL)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(error_str, 2);
	}
	ft_putstr_fd("\n", 2);
}
