#include "../../micro_shell.h"

void	execve_builtin(t_storage *bag, char *arg)
{
	char	buf1[MAXLEN];
	char	buf2[MAXLEN];
	char	*buf[2];
	char	*trim;

	ft_memset(buf1, 0, MAXLEN);
	ft_memset(buf2, 0, MAXLEN);
	ft_memccpy(buf1, arg, ' ', ft_strlen(arg));
	if (buf1[ft_strlen(buf1) - 1] == ' ')
		buf1[ft_strlen(buf1) - 1] = '\0';
	if (ft_strlen(buf1))
	{
		trim = ft_strtrim(ft_strchr(arg, ' ') + 1, " ");
		ft_memcpy(buf2, trim, ft_strlen(trim));
		free(trim);
		buf[0] = cutnjoin(buf2, '\'');
		buf[1] = cutnjoin(buf[0], '\"');
		free(buf[0]);
	}
	if (!ft_strncmp(buf1, "cd", 2))
		builtin_cd(bag, buf[1]);
	else if (!ft_strncmp(buf1, "echo", 4))
		builtin_echo(bag, buf[1]);
	else if (!ft_strncmp(buf1, "pwd", 3))
		builtin_pwd(bag);
	else if (!ft_strncmp(buf1, "exit", 4))
		builtin_exit(bag, buf[1]);
	else if (!ft_strncmp(buf1, "export", 6))
		builtin_export(bag, buf[1]);
	else if (!ft_strncmp(buf1, "env", 3))
		builtin_env(bag);
	else if (!ft_strncmp(buf1, "unset", 5))
		builtin_unset(bag, buf[1]);
	free(buf[1]);
}
