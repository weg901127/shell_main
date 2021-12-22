#include "../../micro_shell.h"
//TODO trim해주기
char	*cutnjoin(char *string, char target)
{
	char	*flag[2];
	char	buf[MAXLEN];

	flag[START] = string;
	flag[END] = string;
	ft_memset(buf, 0, MAXLEN);
	int	tmp = 0;
	while (1)
	{
		tmp = ft_strlen(buf);
		ft_memccpy(buf + tmp, flag[START], target, ft_strlen(flag[START]));
		if (ft_strchr(flag[START], target))
			flag[START] = flag[START] + (ft_strchr(flag[START], target) - flag[START] + 1);
		else
			break;
		if (buf[ft_strlen(buf) - 1] == target)
		{
			if (ft_strlen(buf) && buf[ft_strlen(buf) - 2] == '\\')
				buf[ft_strlen(buf) - 2] = target;
			buf[ft_strlen(buf) - 1] = '\0';
		}
	}
	return ft_strdup(buf);
}



int	*get_zone(char	*string)
{
	int	*buf;
	int	start;
	int	i;

	i = 0;
	start = 0;
	buf = (int *)ft_calloc(ft_strlen(string), sizeof(int));
	while (*string)
	{
		if (*string == '\'')
		{
			buf[i] = 2;
			if (ft_strchr(string + 1, '\''))
				start = !start;
			else if (!ft_strchr(string + 1, '\''))
				start = 0;
		}
		else if (start)
			buf[i] = 0;
		else
			buf[i] = 1;
		string++;
		i++;
	}
	return (buf);
}

int	get_env_len(char *tmp)
{
	int	res;

	res = 0;
	while (*tmp)
	{
		if (ft_isspace(*tmp) || *tmp == '\'' || *tmp =='\"' || *tmp == '$' || *tmp == '|')
			break;
		res++;
		tmp++;
	}
	return (res);
}

char	*parse_env(t_storage *bag, char *string)
{
	char	buf[MAXLEN];
	char	var_buf[MAX_ENVLEN];
	char	*tmp;
	int		buflen;
	int		*zone;

	if (!ft_strchr(string, '$'))
		return (ft_strdup(string));
	tmp = string;
	ft_memset(buf, 0, MAXLEN);
	ft_memset(var_buf, 0, MAX_ENVLEN);
	zone = get_zone(string);
	while (1)
	{
		buflen = ft_strlen(buf);
		ft_memccpy(buf + buflen, tmp, '$', ft_strlen(tmp));
		tmp = ft_strchr(tmp, '$');
		if (tmp)
			tmp += 1;
		if (buf[ft_strlen(buf) - 1] == '$' && zone[ft_strlen(string) - ft_strlen(tmp) - 1] == 1)
		{
			buf[ft_strlen(buf) - 1] = '\0';
			ft_memcpy(var_buf, tmp, get_env_len(tmp));
			tmp = tmp + get_env_len(tmp);
			//TODO get_value NULL처리
			if (get_value(bag->environ, var_buf))
				ft_strlcat(buf, get_value(bag->environ, var_buf), MAXLEN);
		}
		if (!tmp)
			break;
	}
	free(zone);
	return ft_strdup(buf);
}
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
void	execve_cmd(t_storage *bag, char	*arg)
{
	//builtin도 fork태우고 pipe, dup 해준다~
	char	buf[MAXLEN];

	ft_memset(buf, 0, MAXLEN);
	ft_memccpy(buf, arg, ' ', ft_strlen(arg));
	if (buf[ft_strlen(buf) - 1] == ' ')
		buf[ft_strlen(buf) - 1] = '\0';
	if(is_builtin(bag, buf))
		execve_builtin(bag, arg);
}
bool parse_master(t_storage *bag)
{
	char	*buf;
	char	**args;
	int		i;

	i = 0;
	buf = parse_env(bag, bag->input);
	//buf[1] = cutnjoin(buf[0], '\'');
	//buf[2] = cutnjoin(buf[1], '\"');
	//free(buf[0]);
	//free(buf[1]);
	args = ft_split(buf, '|');
	free(buf);
	while (args[i])
	{
		buf = ft_strtrim(args[i++], " ");
		execve_cmd(bag, buf);
		free(buf);
	}
	while (i--)
		free(args[i]);
	free(args);
	return (false);
}
