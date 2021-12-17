/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prase_master.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:45:45 by gilee             #+#    #+#             */
/*   Updated: 2021/12/17 15:37:23 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

char	*cutnjoin(char *string, char target)
{
	char	*flag[2];
	char	buf[10000];

	flag[START] = string;
	flag[END] = string;
	ft_memset(buf, 0, 10000);
	// "'asdf\\\'\\\'"
	int	tmp = 0;
	while (1)
	{
		tmp = ft_strlen(buf);
		ft_memccpy(buf + tmp, flag[START], target, ft_strlen(flag[START]));
		if (ft_strchr(flag[START], target))
			flag[START] = flag[START] + (ft_strchr(flag[START], target) - flag[START] + 1);
		else
			break;
		if (buf[ft_strlen(buf) - 1] == target)
		{
			if (ft_strdup(buf) && buf[ft_strlen(buf) - 2] == '\\')
				buf[ft_strlen(buf) - 2] = target;
			buf[ft_strlen(buf) - 1] = '\0';
		}
		//if (!flag[START])
		//	break;
	}
	printf("output : %s",buf);
	return NULL;
}

int	ft_splitcnt(char **src)
{
	int	cnt;

	cnt = 0;
	if (src == NULL || *src == NULL)
		return (0);
	while(src[cnt][0])
		cnt++;
	return (cnt);
}

int	ft_charcnt(char *src, char target)
{
	int	cnt;

	cnt = 0;
	if (src == NULL || *src == 0)
		return (0);
	while (*src)
	{
		if (*src == target)
			cnt++;
		src++;
	}
	return (cnt);
}

bool parse_master(t_storage *bag)
{
	bool	res;

	res = false;
	//single거의 완료
	cutnjoin(bag->input, '\'');
	//double 처리
	//cutnjoin(bag->input, '\"');
	//$처리
	//명령어 단위로 쪼개서 넘겨줌
	return (res);
}
