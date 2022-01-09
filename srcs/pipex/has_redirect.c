#include "../../micro_shell.h"

static void	free_zone(int *zone_s, int *zone_d)
{
	free(zone_s);
	free(zone_d);
}

static void	check_output_core(t_storage *bag, char *str, char *buf, int *res)
{
	int		*zone_s;
	int		*zone_d;
	int		i;

	i = 0;
	zone_s = get_zone(str, '\'');
	zone_d = get_zone(str, '\"');
	if (buf && buf[0] == '>' && buf[1] == '>' && buf[2] == '>'
		&& zone_s[buf - str] && zone_d[buf - str])
		exit(SYNTEX_ERR);
	else if (buf && buf[0] == '>' && buf[1] != '>'
		&& zone_s[buf - str] && zone_d[buf - str])
	{
		bag->redirect_output = 1;
		*(bag->location_output + i++) = buf - str + 1 + 1000;
		*res |= 1;
	}
	else if (buf && buf[0] == '>' && buf[1] == '>'
		&& zone_s[buf - str] && zone_d[buf - str])
	{
		bag->append = 1;
		buf = buf + 1;
		*(bag->location_output + i++) = buf - str + 1 + 2000;
		*res |= 1;
	}
	free_zone(zone_s, zone_d);
}

static void	check_output(t_storage *bag, char *str, int *res)
{
	char	*buf;

	buf = ft_strchr(str, '>');
	while (buf != NULL)
	{
		check_output_core(bag, str, buf, res);
		buf = ft_strchr(buf + 1, '>');
	}
}

static void	check_input_core(t_storage *bag, char *str, char *buf, int *res)
{
	int		*zone_s;
	int		*zone_d;
	int		i;

	i = 0;
	zone_s = get_zone(str, '\'');
	zone_d = get_zone(str, '\"');
	if (buf && buf[0] == '<' && buf[1] == '<' && buf[2] == '<'
		&& zone_s[buf - str] && zone_d[buf - str])
		buf = buf + 2;
	else if (buf && buf[0] == '<' && buf[1] != '<'
		&& zone_s[buf - str] && zone_d[buf - str])
	{
		bag->redirect_input = 1;
		*(bag->location_input + i++) = (buf - str) + 1 + 1000;
		*res |= 1;
	}
	else if (buf && buf[0] == '<' && buf[1] == '<'
		&& zone_s[buf - str] && zone_d[buf - str])
	{
		bag->heredoc = 1;
		buf = buf + 1;
		*(bag->location_input + i++) = (buf - str) + 1 + 2000;
		*res |= 1;
	}
	free_zone(zone_s, zone_d);
}

static void	check_input(t_storage *bag, char *str, int *res)
{
	char	*buf;

	buf = ft_strchr(str, '<');
	while (buf != NULL)
	{
		check_input_core(bag, str, buf, res);
		buf = ft_strchr(buf + 1, '<');
	}
}

int	has_redirect(t_storage *bag, char *str)
{
	int		res;

	res = 0;
	check_input(bag, str, &res);
	check_output(bag, str, &res);
	return (res);
}
