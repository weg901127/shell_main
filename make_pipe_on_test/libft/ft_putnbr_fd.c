/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 06:45:17 by gilee             #+#    #+#             */
/*   Updated: 2021/06/30 20:16:03 by gilee            ###   ########.fr       */
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

void	ft_putnbr_fd(int n, int fd)
{
	char	res[12];
	int		flag;
	int		len;

	flag = 0;
	if (n < 0)
	{
		flag += 1;
	}
	len = ft_getlen(n);
	ft_memset(res, 0, 12);
	if (flag != 0)
		res[0] = '-';
	while (len)
	{
		res[flag++] = '0' + ft_abs((n / ft_ndec(len)));
		n = ft_abs((n % ft_ndec(len)));
		len--;
	}
	write(fd, res, ft_strlen(res));
}
