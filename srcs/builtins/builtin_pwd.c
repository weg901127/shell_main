#include "../../micro_shell.h"

void	builtin_pwd(t_storage *bag)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		ft_print_error("pwd", NULL, strerror(errno));
		exit(EXIT_FAILURE);
		set_environ(bag, EXIT_FAILURE);
	}
	ft_putendl_fd(pwd, STDOUT_FD);
	free(pwd);
	pwd = NULL;
	exit(EXIT_SUCCESS);
}
