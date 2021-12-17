/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:15:01 by sehhong           #+#    #+#             */
/*   Updated: 2021/12/17 14:48:43 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

void    update_env(t_ArrayList *env, char *key, char *new_val)
{
    int		i;
	char	*data;
    char    *tmp;
    int     len_key;

	i = 0;
    len_key = ft_strlen(key);
	while (i < env->current_element_count)
	{
		data = getALElement(env, i)->data;
		if (!ft_strncmp(data, key, len_key) && data[len_key] == '=')
		{
			data = NULL;
            free(data);
            tmp = ft_strjoin(key, "=");
            data = ft_strjoin(tmp, new_val);
            return ;
		}
        i++;
	}
}
