/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp_exact.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:49:14 by gilee             #+#    #+#             */
/*   Updated: 2022/01/10 10:49:16 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

bool	strncmp_exact(char *str1, char *str2, char c)
{
	int	len_str2;

	len_str2 = ft_strlen(str2);
	if (!str1)
		return (FALSE);
	if (!ft_strncmp(str1, str2, len_str2) && str1[len_str2] == c)
		return (TRUE);
	return (FALSE);
}
