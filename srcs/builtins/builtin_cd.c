/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 00:56:10 by hongsehui         #+#    #+#             */
/*   Updated: 2021/12/15 16:40:39 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

//TODO err code 확인하기!
bool	builtin_cd(t_storage *bag, char *path)
{
	if (chdir(path) == -1)
	{	
		ft_print_error("cd", path, strerror(errno));
		set_exit_status(bag, EXIT_FAILURE);
		return (FALSE);
	}
	set_exit_status(bag, EXIT_SUCCESS);
	return (TRUE);
}

// int	main(void)
// {
// 	t_storage	*bag;

// 	bag = create_bag();
// 	init_bag(bag);
// 	init_environ(bag);
// 	printf("%s", my_which(bag, "ls"));
// 	printf("\033[32;1mDONE\n\033[m");
// }