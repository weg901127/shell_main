#include "../../micro_shell.h"

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
	while (buf[i++])
		;
	res = (char **)ft_calloc(i, sizeof(char *));
	i = 0;
	while (buf[i])
	{
		res[i] = ft_strtrim(buf[i], " |");
		free(buf[i]);
		i++;
	}
	return (res);
}
