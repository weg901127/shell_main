/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 00:56:10 by hongsehui         #+#    #+#             */
/*   Updated: 2021/12/15 16:16:02 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

//TODO err code 확인하기!
int	builtin_cd(t_storage *bag, char *path)
{
	if (chdir(path) == -1)
	{	
		ft_print_error("cd", path, strerror(errno));
		set_exit_status(bag, EXIT_FAILURE);
		return (-1);
	}
	set_exit_status(bag, EXIT_SUCCESS);
	return (0);
}

// int	main(void)
// {
// 	t_storage	*bag;

// 	bag = create_bag();
// 	init_bag(bag);

// }