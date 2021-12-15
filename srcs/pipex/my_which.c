/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_which.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 03:38:59 by gilee             #+#    #+#             */
/*   Updated: 2021/12/14 03:59:47 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

char	*my_which(t_storage *bag, char *cmd)
{
	char	**path;
	char	*tmp1;
	char	*tmp2;
	int		fd;
	int		i;
	
	i = 0;
	if (getpath(bag, &path))
		while (*(path[i]))
		{
			tmp1 = ft_strjoin(path[i], "/");
			tmp2 = ft_strjoin(tmp1, cmd);
			fd = open(tmp2, O_RDONLY);
			if (fd != -1)
			{
				free(tmp1);
				close(fd);
				return (tmp2);
			}
			free(tmp1);
			free(tmp2);
			i++;
		}
	return (NULL);
}
