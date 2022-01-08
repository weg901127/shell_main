#include "../../micro_shell.h"

static int	get_valid_space(char *str, int location)
{
	int		*zone_s;
	int		*zone_d;

	zone_s = get_zone(str, '\'');
	zone_d = get_zone(str, '\"');
	if (zone_s[location] && zone_d[location])
	{
		free(zone_s);
		free(zone_d);
		return (location);
	}
	free(zone_s);
	free(zone_d);
	return (-1);
}


static void	process_split(char **buf, char *str)
{
	char	tmp[MAXLEN];
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	ft_bzero(tmp, sizeof(char) * MAXLEN);
	while(i < (int)ft_strlen(str) + 1)
	{
		if ((str[i] == ' ' && str[i + 1] != ' ' && get_valid_space(str, i) != -1) || !str[i])
		{
			buf[j++] = ft_strdup(tmp);
			k = 0;
			ft_bzero(tmp, sizeof(char) * MAXLEN);
		}
		tmp[k++] = str[i++];
	}
}

char	**split_echo(char *str)
{
	char	*buf[MAXLEN];
	char	**res;
	int		i;

	i = 0;
	ft_memset(buf, 0, sizeof(char *) * MAXLEN);
	process_split(buf, str);
	while (buf[i++])
		;
	res = (char **)ft_calloc(i, sizeof(char *));
	i = 0;
	while (buf[i])
	{
		res[i] = ft_strtrim(buf[i], " ");
		free(buf[i]);
		i++;
	}
	return (res);
}
