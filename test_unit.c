#include <stdio.h>
#include "libft/libft.h"
#include "micro_shell.h"
#include "srcs/array_list/arraylist.h"


//1안
char	*fndnchange(char *string, char target)
{
	int		cnt;
	char	*res;
	char	*tmp;

	res = (char *)ft_calloc(ft_strlen(string), sizeof(char));
	cnt = 0;
	while (*string)
	{
		if (*string == target && (cnt == 0 || *(string - 1) != '\\'))
		{
			string++;
			continue;
		}
		res[cnt] = *string;
		string++;
		cnt++;
	}
	tmp = ft_strdup(res);
	free(res);
	// \'파싱 로직 돌려야함..;;
	return (tmp);
}
//2안
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
	while(src[cnt])
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

int main(int argc, char **argv)
{
	(void)argc;
	printf("input : %s\n", argv[1]);
	cutnjoin(argv[1], '\'');
	return 0;
}
