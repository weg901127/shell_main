#include "../../micro_shell.h"

static void     find_n_rm_element(t_storage *bag, char *key)
{
    int     i;
    char    *data;

    i = 0;
    while (i < bag->environ->current_element_count)
    {
        data = getALElement(bag->environ, i)->data;
        if (strncmp_exact(data, key, '='))
            break ;
        i++;
    }
    if (i < bag->environ->current_element_count)
    {   
        free(data);
        data = NULL;
        removeALElement(bag->environ, i);
    }
}

int builtin_unset(t_storage *bag, char *arg)
{
    int     i;
    char    **arg_arr;

	arg_arr = ft_split(arg, ' ');
    i = 0;
    while (arg_arr[i])
    {   
        find_n_rm_element(bag, arg_arr[i]);
        i++;
    }
    ft_malloc_fail_str(arg_arr, count_str_array(arg_arr));
    return (EXIT_SUCCESS);
}
