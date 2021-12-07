/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 11:34:07 by sehhong           #+#    #+#             */
/*   Updated: 2021/09/26 12:45:56 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cnt_chr(int n)
{
	int		chr_cnt;
	long	nb;

	nb = n;
	chr_cnt = 0;
	if (nb <= 0)
	{
		chr_cnt++;
		nb *= -1;
	}
	while (nb)
	{
		nb /= 10;
		chr_cnt++;
	}
	return (chr_cnt + 1);
}

char	*ft_itoa(int n)
{
	int		chr_num;
	char	*ret;
	int		i;
	long	nb;

	chr_num = cnt_chr(n);
	ret = (char *)malloc(sizeof(char) * chr_num);
	if (!ret)
		return (0);
	nb = n;
	nb = ft_abs_int(nb);
	ret[chr_num - 1] = '\0';
	i = (chr_num - 2);
	while (i)
	{
		ret[i] = (nb % 10 + '0');
		nb /= 10;
		i--;
	}
	if (n >= 0)
		ret[0] = (nb + '0');
	else
		ret[0] = '-';
	return (ret);
}
