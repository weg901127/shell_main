/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 09:53:14 by sehhong           #+#    #+#             */
/*   Updated: 2021/12/16 16:19:18 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

static void    find_n_rm_element(t_storage *bag, char *str)
{
    int     i;
    int     str_len;
    char    *data;

    i = 0;
    str_len = ft_strlen(str);
    while (i < bag->environ->current_element_count)
    {
        data = getALElement(bag->environ, i)->data;
        if (!ft_memcmp(str, data, str_len) && data[str_len + 1] == '=')
            break ;
        i++;
    }
    if (i < bag->environ->current_element_count)
        removeALElement(bag->environ, i);
}

void    builtin_unset(t_storage *bag, char **arg)
{
    //만약 unset asdf qwer와 같이 다수의 인자가 들어오면 둘다 지워줘야 함.
    //while 문으로 인자수만큼 지워줌.
    //명령어 리스트가 어떻게 들어올지는 모르겠지만(char **arg) 맨마지막 인자까지 지워줘야함.
    int i;

    i = 1;
    while (arg[i])
        find_n_rm_element(bag, arg[i]);
    set_env_var(bag, EXIT_SUCCESS);
}
