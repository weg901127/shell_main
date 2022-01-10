/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cutnjoin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:56:00 by gilee             #+#    #+#             */
/*   Updated: 2022/01/10 10:56:00 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

static void	put_err(void)
{
	ft_print_error("SyntaxError", NULL, NULL);
	exit(EXIT_FAILURE);
}

static void	remove_target_char(char *buf, char target)
{
	if (ft_strlen(buf) && buf[ft_strlen(buf) - 2] == '\\')
		buf[ft_strlen(buf) - 2] = target;
	buf[ft_strlen(buf) - 1] = '\0';
}

char	*cutnjoin(char *string, char target)
{
	char	*flag[1];
	char	buf[MAXLEN];
	int		tmp;

	tmp = 0;
	if (ft_charcnt(string, target) & 1)
		put_err();
	flag[START] = string;
	ft_memset(buf, 0, MAXLEN);
	while (1)
	{
		tmp = ft_strlen(buf);
		ft_memccpy(buf + tmp, flag[START], target, ft_strlen(flag[START]));
		if (ft_strchr(flag[START], target))
			flag[START] = flag[START]
				+ (ft_strchr(flag[START], target) - flag[START] + 1);
		else
			break ;
		if (buf[ft_strlen(buf) - 1] == target)
			remove_target_char(buf, target);
	}
	return (ft_strdup(buf));
}
