#include "../../micro_shell.h"

static void	my_free(char ***arg_arr)
{
	int i;

	i = 0;
	while((*arg_arr)[i])
		free((*arg_arr)[i++]);
	free((*arg_arr)[i]);
	free(*arg_arr);
}

int	builtin_echo(char *arg)
{
	int		var[4];
	char	*buf[2];
	char	**buf_split;
	char	**arg_arr;

	ft_bzero(var, sizeof(int) * 4);
	arg_arr = split_echo(arg);
	buf_split = (char **)ft_calloc(ft_splitcnt(arg_arr) + 1, sizeof(char*));
	while (arg_arr[var[2]])
	{
		if (ft_strchr(arg_arr[var[2]], '<') || ft_strchr(arg_arr[var[2]], '>'))
		{
			free(arg_arr[var[2]]);
			arg_arr[var[2]++] = NULL;
			continue ;
		}
		buf_split[var[3]] = arg_arr[var[2]];
		var[2]++;
		var[3]++;
	}
	if (strncmp_exact(buf_split[0], "-n", '\0'))
	{
		var[0] = 1;
		var[1] = 1;
	}
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
	if (!var[1])
		write(1, "\n", 1);
	my_free(&arg_arr);
	return (EXIT_SUCCESS);
}
