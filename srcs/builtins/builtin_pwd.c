#include "../../micro_shell.h"

int	builtin_pwd(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		ft_print_error("pwd", NULL, strerror(errno));
		exit(EXIT_FAILURE);
	}
	ft_putendl_fd(pwd, STDOUT_FD);
	free(pwd);
	pwd = NULL;
	return (EXIT_SUCCESS);	
}
