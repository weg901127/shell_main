#include "../../micro_shell.h"

static char **set_argv(t_storage *bag, char *str)
{
	char	**tmp;
	char	*cmd_tmp;

	tmp = ft_split(str, ' ');
	if (ft_strchr(tmp[0], '<'))
		exit(SYNTAX_ERR);
	if (!ft_strchr(tmp[0], '/'))
	{
		cmd_tmp = my_which(bag, tmp[0]);
		if (!cmd_tmp)
			exit(100);
		free(tmp[0]);
		tmp[0] = cmd_tmp;
	}
	return(tmp);
}

void	my_execve(t_storage *bag, char	*str)
{
	char	**argv;
	int		i;

	i = 0;
	argv = set_argv(bag, str);
	while (argv[i])
	{
		if (ft_strchr(argv[i], '<') || ft_strchr(argv[i], '>'))
		{
			free(argv[i]);
			argv[i] = NULL;
		}
		i++;
	}
	execve(argv[0], argv, get_environ(bag));
	exit(EXIT_FAILURE);
}
