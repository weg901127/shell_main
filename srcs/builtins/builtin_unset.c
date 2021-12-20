#include "../../micro_shell.h"

static void     find_n_rm_element(t_storage *bag, char *key)
{
    int     i;
    int     key_len;
    char    *data;

    i = 0;
    key_len = ft_strlen(key);
    while (i < bag->environ->current_element_count)
    {
        data = getALElement(bag->environ, i)->data;
        if (!strncmp_exact(data, key, '='))
            break ;
        i++;
    }
    if (i < bag->environ->current_element_count)
        removeALElement(bag->environ, i);
}

void    builtin_unset(t_storage *bag, char *arg)
{
    int     i;
    char    **arg_arr;

    arg_arr = split_cmd(arg);
    i = 0;
    while (arg_arr[i])
    {   
        find_n_rm_element(bag, arg_arr[i]);
        i++;
    }
    set_environ(bag, EXIT_SUCCESS);
}
