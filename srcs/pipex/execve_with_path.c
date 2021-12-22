#include "../../micro_shell.h"

void	execve_with_path(t_storage *bag, char *cmd, char *arg)
{
	char	*final_path;
	char	**cmd_arg;
	char	**my_environ;
	
	cmd_arg = split_cmd(arg);
	my_environ = get_environ(bag);
	final_path = my_which(bag, cmd);
	if (!final_path)
		print_error_and_exit("command not found", cmd, ECMD_NOT_FND);
	execve(final_path, cmd_arg, my_environ);
	if (errno == EACCES)
		print_error_and_exit("permission denied", cmd, EPERMS_DND);
	else
		print_execve_error_and_exit(strerror(errno), cmd, EXIT_FAILURE);
}
