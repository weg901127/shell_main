#include "../../micro_shell.h"

//The return status is 0 unless a write error occurs. 
int	builtin_echo(char *arg)
{
	int		n_option;
	char	**arg_arr;
	int		i;

	i = 0;
	n_option = 0;
	arg_arr = split_cmd(arg);
	if (strncmp_exact(arg_arr[0], "-n", '\0'))
	{
		i = 1;
		n_option = 1;
	}
	while (arg_arr[i])
	{	
		if (i > n_option)
			ft_putchar_fd(' ', STDOUT_FD);
		ft_putstr_fd(arg_arr[i++], STDOUT_FD);
	}
	if (!n_option)
		write(1, "\n", 1);
	ft_malloc_fail_str(arg_arr, count_str_array(arg_arr));
	return (EXIT_SUCCESS);
}
