/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 10:23:32 by gilee             #+#    #+#             */
/*   Updated: 2021/06/30 19:59:21 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getlen(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = (int)(n / 10);
		if (n < 0)
			n *= -1;
		count++;
	}
	return (count);
}

static int	ft_ndec(int len)
{
	int	res;

	res = 1;
	len -= 1;
	while (len--)
	{
		res *= 10;
	}
	return (res);
}

static int	ft_abs(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		flag;
	int		len;

	if (n < INT_MIN || n > INT_MAX)
		return (NULL);
	flag = 0;
	if (n < 0)
	{
		flag += 1;
	}
	len = ft_getlen(n);
	res = (char *)ft_calloc(len + flag + 1, sizeof(char));
	if (!res)
		return (NULL);
	if (flag != 0)
		res[0] = '-';
	while (len)
	{
		res[flag++] = '0' + ft_abs((n / ft_ndec(len)));
		n = ft_abs((n % ft_ndec(len)));
		len--;
	}
	return (res);
}
