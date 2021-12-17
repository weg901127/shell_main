/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 07:37:03 by sehhong           #+#    #+#             */
/*   Updated: 2021/12/17 16:03:58 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

//TODO err code 확인하기!
//cmd 리스트를 확인했을 때, cd 뒤에 경로가 있을경우만, chdir(path)
//->리스트 형태 정해지면 추가할것.
//cd ~ b c d
//{"cd"},{"~ b c d"}
bool	builtin_cd(t_storage *bag, char *path)
{
	// if (!path)
	// path = "home"
	if (chdir(path) == -1)
	{	
		ft_print_error("cd", path, strerror(errno));
		set_env_var(bag, EXIT_FAILURE);
		return (FALSE);
	}
	set_env_var(bag, EXIT_SUCCESS);
	return (TRUE);
}

