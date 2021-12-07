/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_fail_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 20:06:11 by sehee             #+#    #+#             */
/*   Updated: 2021/09/26 10:06:34 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_malloc_fail_int(int **arr, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
