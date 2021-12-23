#include "../../micro_shell.h"

void	execve_cmd(t_storage *bag, char *arg)
{
	//builtin도 fork태우고 pipe, dup 해준다~
	char	cmd[MAXLEN];

	ft_memset(cmd, 0, MAXLEN);
	ft_memccpy(cmd, arg, ' ', ft_strlen(arg));
	if (cmd[ft_strlen(cmd) - 1] == ' ')
		cmd[ft_strlen(cmd) - 1] = '\0';

	if(is_builtin(bag, cmd))
		execve_builtin(bag, arg);
	else
		execve_with_path(bag, cmd, arg);
}
