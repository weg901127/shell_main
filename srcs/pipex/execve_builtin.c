#include "../../micro_shell.h"

static void	my_free(char ***arg_arr)
{
	int	i;

	i = 0;
	while ((*arg_arr)[i])
		free((*arg_arr)[i++]);
	free(*arg_arr);
}

static void	remove_redirection(char *arg, char *dest)
{
	char	**split;
	char	**buf;
	int		var[2];

	ft_bzero(var, sizeof(int) * 2);
	split = split_echo(arg);
	buf = (char **)ft_calloc(ft_splitcnt(split), sizeof(char *));
	while (split[var[0]])
	{
		if (ft_strchr(split[var[0]], '<') || ft_strchr(split[var[0]], '>'))
		{
			free(split[var[0]]);
			split[(var[0])++] = NULL;
			continue ;
		}
		buf[var[1]] = split[var[0]];
		ft_strlcat(dest, buf[var[1]], MAXLEN);
		ft_strlcat(dest, " ", MAXLEN);
		(var[0])++;
		(var[1])++;
	}
	my_free(&split);
}

static void	do_execve(t_storage *bag, char *cmd, char *args, int *exit_status)
{
	if (strncmp_exact(cmd, "cd", '\0'))
		*exit_status = builtin_cd(bag, args);
	else if (strncmp_exact(cmd, "pwd", '\0'))
		*exit_status = builtin_pwd();
	else if (strncmp_exact(cmd, "exit", '\0'))
		*exit_status = builtin_exit(bag, args);
	else if (strncmp_exact(cmd, "export", '\0'))
		*exit_status = builtin_export(bag, args);
	else if (strncmp_exact(cmd, "env", '\0'))
		*exit_status = builtin_env(bag);
	else if (strncmp_exact(cmd, "unset", '\0'))
		*exit_status = builtin_unset(bag, args);
}

static int	execve_core(t_storage *bag, char *buf[])
{
	char	buf1[MAXLEN];
	int		exit_status;

	ft_bzero(buf1, MAXLEN);
	exit_status = 127;
	ft_memccpy(buf1, buf[0], ' ', ft_strlen(buf[0]));
	if (buf1[ft_strlen(buf1) - 1] == ' ')
		buf1[ft_strlen(buf1) - 1] = '\0';
	buf[1] = ft_strtrim(buf[0] + ft_strlen(buf1), " ");
	if (strncmp_exact(buf1, "echo", '\0'))
		exit_status = builtin_echo(buf[1]);
	buf[2] = parse_space(buf[1]);
	buf[3] = cutnjoin(buf[2], '\'');
	buf[4] = cutnjoin(buf[3], '\"');
	do_execve(bag, buf1, buf[4], &exit_status);
	free(buf[0]);
	free(buf[1]);
	free(buf[2]);
	free(buf[3]);
	free(buf[4]);
	return (exit_status);
}

int	execve_builtin(t_storage *bag, char *arg)
{
	char	dest[MAXLEN];
	char	*buf[5];

	remove_redirection(arg, dest);
	buf[0] = ft_strtrim(dest, " ");
	return (execve_core(bag, buf));
}
