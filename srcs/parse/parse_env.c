/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:56:24 by gilee             #+#    #+#             */
/*   Updated: 2022/01/10 10:56:25 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

static void	parse_env_core(t_storage *bag, char *buf, char *var_buf, char *tmp)
{
	if (get_env_len(tmp))
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
		if (get_value(bag->environ, var_buf))
			ft_strlcat(buf, get_value(bag->environ, var_buf), MAXLEN);
	}
}

static int	*set_zone(int is_heredoc, char *string)
{
	int	*zone;

	if (is_heredoc)
		zone = (int *)ft_calloc(ft_strlen(string), sizeof(int));
	else
		zone = get_zone(string, '\'');
	return (zone);
}

static void	init_var(char *buf, char *var_buf)
{
	ft_memset(buf, 0, MAXLEN);
	ft_memset(var_buf, 0, MAX_ENVLEN);
}

static int	isenv(char *tmp, char *buf)
{
	return (tmp && buf[ft_strlen(buf) - 1] == '$');
}

char	*parse_env(t_storage *bag, char *string, int i)
{
	char	buf[MAXLEN];
	char	var_buf[MAX_ENVLEN];
	char	*tmp;
	int		buflen;
	int		*zn;

	if (!ft_strchr(string, '$'))
		return (ft_strdup(string));
	tmp = string;
	zn = set_zone(i, string);
	init_var(buf, var_buf);
	while (1)
	{
		buflen = ft_strlen(buf);
		ft_memccpy(buf + buflen, tmp, '$', ft_strlen(tmp));
		tmp = ft_strchr(tmp, '$');
		if (tmp)
			tmp += 1;
		if (isenv(tmp, buf) && zn[ft_strlen(string) - ft_strlen(tmp) - 1] == !i)
			parse_env_core(bag, buf, var_buf, tmp);
		if (!tmp)
			break ;
	}
	free(zn);
	return (ft_strdup(buf));
}
