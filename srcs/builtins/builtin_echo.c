#include "../../micro_shell.h"

static void	my_free(char ***arg_arr)
{
	int	i;

	i = 0;
	while ((*arg_arr)[i])
		free((*arg_arr)[i++]);
	free(*arg_arr);
}

static void	print(char **buf_split, char *buf[], int *var)
{
	while (buf_split[var[0]])
	{	
		if (var[0] > var[1])
			ft_putchar_fd(' ', STDOUT_FD);
		buf[0] = cutnjoin(buf_split[var[0]++], '\'');
		buf[1] = cutnjoin(buf[0], '\"');
		ft_putstr_fd(buf[1], STDOUT_FD);
		free(buf[0]);
		free(buf[1]);
	}
}

int	builtin_echo(char *arg)
{
	int		var[2];
	char	*buf[2];
	char	**arg_arr;

	ft_bzero(var, sizeof(int) * 2);
	arg_arr = split_echo(arg);
	if (strncmp_exact(arg_arr[0], "-n", '\0'))
	{
		var[0] = 1;
		var[1] = 1;
	}
	print(arg_arr, buf, var);
	if (!var[1])
		write(1, "\n", 1);
	my_free(&arg_arr);
	return (EXIT_SUCCESS);
}
