#include "../../micro_shell.h"
//TODO trim해주기
char	*cutnjoin(char *string, char target)
{
	char	*flag[2];
	char	buf[MAXLEN];

	if (ft_charcnt(string, target) & 1)
	{
		ft_print_error("syntax error", NULL, NULL);
		exit(EXIT_FAILURE);
	}
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

bool parse_master(t_storage *bag)
{
	char	*buf;
	char	**args;
	int		i;

	i = 0;
	buf = parse_env(bag, bag->input);
	args = ft_split(buf, '|');
	free(buf);
	pipex(bag, args);
	// while (args[i])
	// {
	// 	buf = ft_strtrim(args[i++], " ");
	// 	execve_cmd(bag, buf);
	// 	free(buf);
	// }
	while (i--)
		free(args[i]);
	free(args);
	return (false);
}
