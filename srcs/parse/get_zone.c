/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_zone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:56:13 by gilee             #+#    #+#             */
/*   Updated: 2022/01/10 10:56:14 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

void	free_zone(int *zone_s, int *zone_d)
{
	free(zone_s);
	free(zone_d);
}

void	init_zone(int **zone_s, int **zone_d, char **str)
{
	*zone_s = get_zone(*str, '\'');
	*zone_d = get_zone(*str, '\"');
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
		if (*string == target && *(string - 1) != '\\')
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
