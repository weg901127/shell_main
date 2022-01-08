#include "../../micro_shell.h"

int	execve_builtin(t_storage *bag, char *arg)
{
	char	buf1[MAXLEN];
	char	*buf[5];
	int		exit_status;

	exit_status = -1;
	ft_memset(buf1, 0, MAXLEN);
	buf[0] = ft_strtrim(arg, " ");
	ft_memccpy(buf1, buf[0], ' ', ft_strlen(buf[0]));
	if (buf1[ft_strlen(buf1) - 1] == ' ')
		buf1[ft_strlen(buf1) - 1] = '\0';
	buf[1] = ft_strtrim(buf[0] + ft_strlen(buf1), " ");
	if (strncmp_exact(buf1, "echo", '\0'))
		exit_status = builtin_echo(buf[1]);
	buf[2] = parse_space(buf[1]);
	buf[3] = cutnjoin(buf[2], '\'');
	buf[4] = cutnjoin(buf[3], '\"');
	if (strncmp_exact(buf1, "cd", '\0'))
		exit_status = builtin_cd(bag, buf[4]);
	else if (strncmp_exact(buf1, "pwd", '\0'))
		exit_status = builtin_pwd();
	else if (strncmp_exact(buf1, "exit", '\0'))
		exit_status = builtin_exit(bag, buf[4]);
	else if (strncmp_exact(buf1, "export", '\0'))
		exit_status = builtin_export(bag, buf[4]);
	else if (strncmp_exact(buf1, "env", '\0'))
		exit_status = builtin_env(bag);
	else if (strncmp_exact(buf1, "unset", '\0'))
		exit_status = builtin_unset(bag, buf[4]);
	free(buf[0]);
	free(buf[1]);
	free(buf[2]);
	free(buf[3]);
	free(buf[4]);
	return (exit_status);
}
