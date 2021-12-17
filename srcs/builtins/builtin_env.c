/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 09:16:13 by sehhong           #+#    #+#             */
/*   Updated: 2021/12/16 16:17:24 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

//TODO error code -> exit code? 아직까진 에러가 나는 상황을 본적없음.
void    builtin_env(t_storage *bag)
{
    int     i;
    char    *data;
    
    i = 0;
    set_env_var(bag, EXIT_SUCCESS);
    while (i < bag->environ->current_element_count)
    {
        data = getALElement(bag->environ, i)->data;
        ft_putendl_fd(data, 1);
        i++;
    }
}
