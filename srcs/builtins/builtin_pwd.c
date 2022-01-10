/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:48:21 by gilee             #+#    #+#             */
/*   Updated: 2022/01/10 10:48:23 by gilee            ###   ########.fr       */
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
		exit(EXIT_FAILURE);
	}
	ft_putendl_fd(pwd, STDOUT_FD);
	free(pwd);
	pwd = NULL;
	return (EXIT_SUCCESS);
}
