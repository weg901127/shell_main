#include "../../micro_shell.h"

static  int    where_is_equal(char *str)
{
    int i;
    
    i = 0;
    while (str[i])
    {
        if (str[i] == '=')
            return (i);
        i++;
    }
    //'='가 없다.
    if (str[i] == '\0') 
        return(-1);
}

static void    export_no_option(t_storage *bag)
{
    int i;

    i = 0;
    while (i < bag->environ->current_element_count)
    {
        ft_putstr_fd("declare -x ", STDOUT_FD);
        ft_putendl_fd(getALElement(bag->environ, i)->data, STDOUT_FD);
        i++;
    }   
}

static void    add_name_on_env(t_storage *bag, char *key_value, int equal_here)
{
    char            key[10000];
    t_ArrayListNode element;
    
    ft_memccpy(key, key_value, '=', equal_here);
    key[equal_here] = '\0';
    if (get_value(bag->environ, key))
        update_env(bag->environ, key, key + equal_here + 1);
    else
    {
        element.data = key_value;
        addALElement(bag->environ, bag->environ->current_element_count -1, element);
    }
}

void    builtin_export(t_storage *bag, char *arg)
{
    char    **arg_arr;
    int     i;
    int     equal_here;

    arg_arr = split_cmd(arg);
    equal_here = 0;
    i = 0;
    set_environ(bag, EXIT_SUCCESS);
    if (arg_arr[0] == NULL)
        export_no_option(bag);
    // 다른 인자가 있을 때
    else
    {
        while (arg_arr[i])
        {
            equal_here = where_is_equal(arg_arr[i]);
            if (!equal_here)   //export =hihi 
            {
                set_environ(bag, EXIT_FAILURE);
                ft_print_error("export", arg_arr[i], "not a valid identifier");
            }
            else if (equal_here == -1)   //export water
                update_env(bag->environ, arg_arr[i], get_value(bag->runtime_env, arg_arr[i]));
            else    //export water=hihi
                add_name_on_env(bag, arg_arr[i], equal_here);
            i++;
        }
    }
}
