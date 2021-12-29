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

//Exit the shell, returning a status of n to the shell’s parent. 
//If n is omitted, the exit status is that of the last command executed. 
void    builtin_exit(t_storage *bag, char *arg)
{
    int     last_exit_status;
    char    **arg_arr;
    int     len_arr;
    
    arg_arr = split_cmd(arg);
    len_arr = count_str_array(arg_arr);
    last_exit_status = ft_atoi(get_value(bag->runtime_env, "?"));
    ft_putendl_fd("exit", 1);
    if (!len_arr)   //exit
        exit(last_exit_status);
    if (!is_only_digit(arg_arr[0])) //exit abc 
    {
        ft_print_error("exit", arg_arr[0], "numeric argument required");
        exit(255);
    }
    if (len_arr == 1)   //exit 1
        exit(ft_atoi(arg_arr[0]) % 256);
    ft_print_error("exit", NULL, "too many arguments");     //exit 1 2 3
    ft_malloc_fail_str(arg_arr, len_arr);
    exit(EXIT_FAILURE);
}
