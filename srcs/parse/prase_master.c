#include "../../micro_shell.h"
//TODO trim해주기
char	*cutnjoin(char *string, char target)
{
	char	*flag[1];
	char	buf[MAXLEN];

	if (ft_charcnt(string, target) & 1)
	{
		ft_print_error("SyntaxError", NULL, NULL);
		exit(EXIT_FAILURE);
	}
	flag[START] = string;
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

int	*get_zone(char	*string, int target)
{
	int	*buf;
	int	start;
	int	i;

	i = 0;
	start = 0;
	buf = (int *)ft_calloc(ft_strlen(string), sizeof(int));
	while (*string)
	{
		if (*string == target)
		{
			buf[i] = 2;
			if (ft_strchr(string + 1, target))
				start = !start;
			else if (!ft_strchr(string + 1, target))
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
	zone = get_zone(string, '\'');
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
			if (*tmp == '?')
			{
				tmp++;
				if (get_value(bag->runtime_env, "?"))
					ft_strlcat(buf, get_value(bag->runtime_env, "?"), MAXLEN);
			}
			else
			{
				ft_memcpy(var_buf, tmp, get_env_len(tmp));
				tmp = tmp + get_env_len(tmp);
				//TODO get_value NULL처리 -> 햇음! 확인부탁!
				if (get_value(bag->environ, var_buf))
					ft_strlcat(buf, get_value(bag->environ, var_buf), MAXLEN);
				// if (get_value(bag->runtime_env, var_buf))
				// 	ft_strlcat(buf, get_value(bag->runtime_env, var_buf), MAXLEN);
			}
		}
		if (!tmp)
			break;
	}
	free(zone);
	return ft_strdup(buf);
}

int	get_valid_pipe(char *str, int location)
{
	int		*zone_s;
	int		*zone_d;

	zone_s = get_zone(str, '\'');
	zone_d = get_zone(str, '\"');
	if (zone_s[location] == 1 && zone_d[location] == 1)
	{
		free(zone_s);
		free(zone_d);
		return (location);
	}
	return (-1);
}

void	split_core(char **buf, char **str, int *var, char **tmp)
{
	char	buf2[MAXLEN];

	ft_memset(buf2, 0, MAXLEN);
	*tmp = ft_strchr(*tmp + 1, '|');
	if (*tmp)
		var[3] = get_valid_pipe(*str, *tmp - *str);
	else
	{
		ft_memccpy(buf2, *str + var[1], 0, 1000);
		buf[var[0]] = ft_strdup(buf2);
		var[3] = -1;
	}
	if (var[3] != -1)
	{
		if (!var[1])
			var[2] = 0;
		else
			var[2] = 1;
		ft_memccpy(buf2, *tmp - (var[3] - var[1]) + var[2], '|', 1000);
		buf2[ft_strlen(buf2) - 1] = '\0';
		if (ft_strlen(buf2))
			buf[var[0]++] = ft_strdup(buf2);
		var[1] = var[3];
	}
}

void	process_split(char **buf, char *str)
{
	char	*tmp;
	int		var[4];

	tmp = str;
	ft_memset(var, 0, sizeof(int) * 4);
	while (tmp)
		split_core(buf, &str, var, &tmp);
}
char	**split_pipe(char *str)
{
	char	*buf[MAXLEN];
	char	**res;
	int		i;

	i = 0;
	(void)res;
	ft_memset(buf, 0, sizeof(char *) * MAXLEN);
	process_split(buf, str);
	while(buf[i++])
		;
	res = (char **)ft_calloc(i, sizeof(char *));
	i = 0;
	while (buf[i])
	{
		res[i] = ft_strtrim(buf[i], " |");
		free(buf[i]);
		i++;
	}
	return res;
}
bool parse_master(t_storage *bag)
{
	char	*buf;
	char	**args;
	int		i;

	i = 0;
	buf = parse_env(bag, bag->input);
	args = split_pipe(buf);
	free(buf);
	pipex(bag, args);
	while (args[i])
		free(args[i++]);
	free(args);
	return (false);
}
