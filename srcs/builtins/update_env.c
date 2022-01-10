/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:49:24 by gilee             #+#    #+#             */
/*   Updated: 2022/01/10 10:53:41 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

static void	add_env(t_arraylist *env, char *key, char *new_val)
{
	t_arraylistnode	element;
	char			*tmp;

	tmp = key;
	if (ft_strlen(new_val))
		tmp = ft_strjoin(key, "=");
	element.data = ft_strjoin(tmp, new_val);
	if (ft_strlen(new_val))
		free(tmp);
	tmp = NULL;
	add_alelement(env, env->current_element_count, element);
}

static void	my_free(void *data)
{
	free(data);
	data = NULL;
}

void	update_env(t_arraylist *env, char *key, char *new_val)
{
	int		i;
	char	*data;
	char	*tmp;

	i = 0;
	tmp = key;
	while (i < env->current_element_count)
	{
		data = get_alelement(env, i)->data;
		if (strncmp_exact(data, key, '='))
		{
			my_free(data);
			if (ft_strlen(new_val))
				tmp = ft_strjoin(key, "=");
			data = ft_strjoin(tmp, new_val);
			if (ft_strlen(new_val))
				free(tmp);
			tmp = NULL;
			get_alelement(env, i)->data = data;
			return ;
		}
		i++;
	}
	if (i == env->current_element_count)
		add_env(env, key, new_val);
}
