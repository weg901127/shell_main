#include "../../micro_shell.h"

char	*parse_space(char *string)
{
	char	buf[MAXLEN];
	int		i;
	int		single_q;
	int		double_q;

	i = 0;
	single_q = 0;
	double_q = 0;
	while(*string)
	{
		if (*string == '\'')
			single_q = !single_q;
		else if (*string == '\"')
			double_q = !double_q;
		if (single_q || double_q)
			buf[i] = *string;
		else
		{
			if (*string == ' ' && *(string - 1) == ' ')
			{
				string++;
				continue;
			}
		}
		i++;
		string++;
	}
	return ft_strdup(buf);
}

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
		//tmp free
		tmp = ft_strchr(arg, ' ');
		if (tmp)
		{
			trim = ft_strtrim(ft_strchr(arg, ' ') + 1, " ");
			// ft_putendl_fd(trim, 2);
			ft_memcpy(buf2, trim, ft_strlen(trim));
			free(trim);
		}
		// trim = ft_strtrim(ft_strchr(arg, ' ') + 1, " ");
		// // ft_putendl_fd(trim, 2);
		// ft_memcpy(buf2, trim, ft_strlen(trim));
		// free(trim);
		buf[0] = cutnjoin(buf2, '\'');
		buf[1] = cutnjoin(buf[0], '\"');
		free(buf[0]);
	}
	// ft_putendl_fd(buf[1], 2);
	if (strncmp_exact(buf1, "cd", '\0'))
		exit_status = builtin_cd(bag, buf[1]);
	else if (strncmp_exact(buf1, "echo", '\0'))
		exit_status = builtin_echo(buf[1]);
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
	free(buf[1]);
	return (exit_status);
}
