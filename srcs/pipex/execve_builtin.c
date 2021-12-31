#include "../../micro_shell.h"

int	execve_builtin(t_storage *bag, char *arg)
{
	char	buf1[MAXLEN];
	char	buf2[MAXLEN];
	char	*buf[2];
	char	*trim;
	char	*tmp;
	int		exit_status;

	exit_status = -1;
	ft_memset(buf1, 0, MAXLEN);
	ft_memset(buf2, 0, MAXLEN);
	ft_memccpy(buf1, arg, ' ', ft_strlen(arg));
	if (buf1[ft_strlen(buf1) - 1] == ' ')
		buf1[ft_strlen(buf1) - 1] = '\0';
	if (ft_strchr(buf1, '<'))
		exit(SYNTAX_ERR);
	if (ft_strlen(buf1))
	{
		tmp = ft_strchr(arg, ' ');
		if (tmp)
		{
			trim = ft_strtrim(ft_strchr(arg, ' ') + 1, " ");
			ft_memcpy(buf2, trim, ft_strlen(trim));
			free(trim);
		}
		buf[1] = parse_space(buf2);
		if (strncmp_exact(buf1, "echo", '\0'))
		{
			exit_status = builtin_echo(buf[1]);
			free(buf[1]);
			return (exit_status);
		}
		buf[0] = cutnjoin(buf[1], '\'');
		buf[1] = cutnjoin(buf[0], '\"');
	}
	if (strncmp_exact(buf1, "cd", '\0'))
		exit_status = builtin_cd(bag, buf[1]);
	//else if (strncmp_exact(buf1, "echo", '\0'))
	//	exit_status = builtin_echo(buf[1]);
	else if (strncmp_exact(buf1, "pwd", '\0'))
		exit_status = builtin_pwd();
	else if (strncmp_exact(buf1, "exit", '\0'))
		exit_status = builtin_exit(bag, buf[1]);
	else if (strncmp_exact(buf1, "export", '\0'))
		exit_status = builtin_export(bag, buf[1]);
	else if (strncmp_exact(buf1, "env", '\0'))
		exit_status = builtin_env(bag);
	else if (strncmp_exact(buf1, "unset", '\0'))
		exit_status = builtin_unset(bag, buf[1]);
	//free(buf[1]);
	return (exit_status);
}
