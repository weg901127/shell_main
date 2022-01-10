/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prase_master.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:56:34 by gilee             #+#    #+#             */
/*   Updated: 2022/01/10 10:56:35 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

bool	parse_master(t_storage *bag)
{
	char	*buf;
	char	**args;
	int		i;

	i = 0;
	buf = parse_env(bag, bag->input, FALSE);
	args = split_pipe(buf);
	free(buf);
	pipex(bag, args);
	while (args[i])
		free(args[i++]);
	free(args);
	return (false);
}
