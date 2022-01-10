/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:48:30 by gilee             #+#    #+#             */
/*   Updated: 2022/01/10 10:48:37 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

static int	find_n_rm_element(t_storage *bag, char *key)
{
	int		i;
	char	*data;

	i = 0;
	while (i < bag->environ->current_element_count)
	{
		data = get_alelement(bag->environ, i)->data;
		if (strncmp_exact(data, key, '='))
			break ;
		i++;
	}
	if (i < bag->environ->current_element_count)
	{
		free(data);
		data = NULL;
		remove_alelement(bag->environ, i);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int	builtin_unset(t_storage *bag, char *arg)
{
	int		i;
	char	**arg_arr;

	arg_arr = ft_split(arg, ' ');
	i = 0;
	while (arg_arr[i])
	{
		if (!find_n_rm_element(bag, arg_arr[i]))
			return (EXIT_SUCCESS);
		i++;
	}
	ft_malloc_fail_str(arg_arr, count_str_array(arg_arr));
	return (EXIT_FAILURE);
}
