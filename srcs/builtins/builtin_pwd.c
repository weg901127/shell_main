/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 09:17:06 by sehhong           #+#    #+#             */
/*   Updated: 2021/12/16 09:17:15 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

void	builtin_pwd(t_storage *bag)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		ft_print_error("pwd", NULL, strerror(errno));
		set_env_var(bag, EXIT_FAILURE);
	}
	ft_putendl_fd(pwd, 1);
	pwd = NULL;
	free(pwd);
    set_env_var(bag, EXIT_SUCCESS);
}
