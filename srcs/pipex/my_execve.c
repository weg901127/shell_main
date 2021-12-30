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

// static void	print_error(char *str, char *str2, int exit_status)
// {
// 	ft_putstr_fd("micro_shell: ", 2);
// 	ft_putstr_fd(str, 2);
// 	if (str2 != NULL)
// 	{
// 		ft_putstr_fd(": ", 2);
// 		ft_putstr_fd(str2, 2);
// 	}
// 	ft_putstr_fd("\n", 2);
// 	exit(exit_status);
// }

void	my_execve(t_storage *bag, char	*str)
{
	char	**argv;
	int		i;
	int		exit_status;

	i = 0;
	//이거 왜 여기에써놓으셨나요... is_builtin이런거 만들어뒀는데... 지워주세요...
	//제발 하나에 다 때려박지마세요... 힘들어요
	exit_status = execve_builtin(bag, str);
	//exit_status == -1 일 경우는 builtin이 실행되지 않은 경우.
	if (exit_status != -1)
		exit(exit_status);
	argv = set_argv(bag, str);
	// if (!argv[0])
	// 	print_error("command not found", argv[0], ECMD_NOT_FND);
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
	// print_error(strerror(errno), argv[0], EXIT_FAILURE);
	exit(EXIT_FAILURE);
}
