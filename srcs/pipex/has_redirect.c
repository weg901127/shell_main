#include "../../micro_shell.h"

static void	check_output(t_storage *bag, char *str, int *res)
{
	char	*buf;
	int		*zone_s;
	int		*zone_d;
	
	buf = ft_strchr(str, '>');
	zone_s = get_zone(str, '\'');
	zone_d = get_zone(str, '\"');
	while (buf != NULL)
	{
		if (buf && buf[0] == '>' && buf[1] != '>'
				&& zone_s[buf - str]
				&& zone_d[buf - str])
		{
			(bag->redirect_output)++;
			*res |= 1;
		}
		else if (buf && buf[0] == '>' && buf[1] == '>'
				&& zone_s[buf - str]
				&& zone_d[buf - str])
		{
			(bag->append)++;
			buf = buf + 1;
			*res |= 1;
		}
		buf = ft_strchr(buf + 1, '>');
	}
}

static void	check_input(t_storage *bag, char *str, int *res)
{
	char	*buf;
	int		*zone_s;
	int		*zone_d;
	
	buf = ft_strchr(str, '<');
	zone_s = get_zone(str, '\'');
	zone_d = get_zone(str, '\"');
	while (buf != NULL)
	{
		if (buf && buf[0] == '<' && buf[1] != '<'
				&& zone_s[buf - str]
				&& zone_d[buf - str])
		{
			(bag->redirect_input)++;
			*res |= 1;
		}
		else if (buf && buf[0] == '<' && buf[1] == '<'
				&& zone_s[buf - str]
				&& zone_d[buf - str])
		{
			(bag->heredoc)++;
			buf = buf + 1;
			*res |= 1;
		}
		buf = ft_strchr(buf + 1, '<');
	}
}

int		has_redirect(t_storage *bag, char *str)
{
	int		res;

	res = 0;
	check_input(bag, str, &res);
	check_output(bag, str, &res);
	return (res);
}
