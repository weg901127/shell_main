#include "../../micro_shell.h"
//TODO 옵션 처리 알아서 하기
//TODO
//The return status is 0 unless a write error occurs. 
void	builtin_echo(t_storage *bag, char *arg, int n_option)
{
	// char	**arg_arr;
	// int		len_arr;

	// arg_arr = split_cmd(arg);
	// len_arr = count_str_array(arg_arr);
	ft_putstr_fd(arg, 1);
	if (!n_option)
		write(1, "\n", 1);
	// if (!len_arr)
	// 	update_env(bag->environ, "_", "echo");
	// else
	// 	update_env(bag->environ, "_", arg_arr[len_arr- 1]);
	set_environ(bag, EXIT_SUCCESS);
}
