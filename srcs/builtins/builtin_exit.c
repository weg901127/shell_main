#include "../../micro_shell.h"

static  bool is_only_digit(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (FALSE);
        i++;
    }
    return(TRUE);
}

int builtin_exit(t_storage *bag, char *arg)
{
    int     last_exit_status;
    char    **arg_arr;
    int     len_arr;
    
	arg_arr = ft_split(arg, ' ');
    len_arr = count_str_array(arg_arr);
    last_exit_status = ft_atoi(get_value(bag->runtime_env, "?"));
    ft_putendl_fd("exit", 1);
    if (!len_arr)
        exit(last_exit_status);
    if (!is_only_digit(arg_arr[0]))
    {
        ft_print_error("exit", arg_arr[0], "numeric argument required");
        exit(255);
    }
    if (len_arr == 1)
        exit(ft_atoi(arg_arr[0]) % 256);
    ft_print_error("exit", NULL, "too many arguments");
    ft_malloc_fail_str(arg_arr, len_arr);
    return (EXIT_FAILURE);
}
