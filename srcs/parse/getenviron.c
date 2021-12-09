/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenviron.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:18:54 by gilee             #+#    #+#             */
/*   Updated: 2021/12/09 15:03:38 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

void	ft_strcpy(char *dest, char *src)
{
	while (*src != '\0')
		*dest++ = *src++;
	*dest = '\0';
}

void	str_malloc_and_insert(char **cmd, char *str, int len, int index)
{
	cmd[index] = (char *)malloc(sizeof(char) * (len + 1));
	// if (!cmd[index])
	// {
	// 	// malloc free 해주기
	// 	print_erro_and_exit("malloc() has failed.\n", NULL, -1);
	// }
	ft_strcpy(cmd[index], str);
}

char **getenviron(t_storage *bag)
{
	char	**ret;
	int		i;
	char	*tmp_data;

	ret = (char **)malloc((bag->environ->currentElementCount + 1) * sizeof(char *));
	i = 0;
	while (i < bag->environ->currentElementCount)
	{
		tmp_data = getALElement(bag->environ, i)->data;
		str_malloc_and_insert(ret, tmp_data, ft_strlen(tmp_data), i);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
