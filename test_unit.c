#include <stdio.h>
#include "libft/libft.h"
#include "micro_shell.h"
#include "srcs/array_list/arraylist.h"

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
int	*get_zone(char	*string)
{
	int	*buf;
	int	start;
	int	i;

	i = 0;
	start = 0;
	buf = (int *)ft_calloc(ft_strlen(string), sizeof(int));
	while(*string)
	{
		if (*string == '\'')
		{
			buf[i] = 2;
			if (ft_strchr(string + 1, '\''))
				start = !start;
			else if (!ft_strchr(string + 1, '\''))
				start = 0;
		}
		else if (start)
			buf[i] = 0;
		else
			buf[i] = 1;
		string++;
		i++;
	}
	for(int j = 0; j < i ; j++)
		printf("%d", buf[j]);
	printf("\n");
	return NULL;
}
/*
char	*putenv(char *string)
{
	char	buf[10000];
	char	*cur;
	int		quote;
	int		cnt;

	cnt = 0;
	quote = 0;
	cur = string;
	ft_memset(buf, 0, 10000);
	if (!ft_strchr(string, '$'))
		return (string);
	ft_memccpy(buf, string, '$', ft_strlen(cur));
	cnt = ft_charcnt(buf, '\'');
	while (cnt--)
		quote = !quote;
	
}
*/
char	*cutnjoin(char *string, char target)
{
	char	*flag[2];
	char	buf[10000];
	int		start;

	start = 0;
	flag[START] = string;
	ft_memset(buf, 0, 10000);
	int	tmp = 0;
	while (1)
	{
		tmp = ft_strlen(buf);
		start = !start;
		ft_memccpy(buf + tmp, flag[START], target, ft_strlen(flag[START]));
		if (ft_strchr(flag[START], target))
			flag[START] = flag[START] + (ft_strchr(flag[START], target) - flag[START] + 1);
		else
			break;
		if (buf[ft_strlen(buf) - 1] == target)
			buf[ft_strlen(buf) - 1] = '\0';
	}
	//printf("output : %s",buf);
	return ft_strdup(buf);
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

int main(int argc, char **argv)
{
	char	*str = "asafds$aa \'$\'afsdafasdf$aa";
	(void)argc;
	(void)argv;
	
	printf("%s\n",str);
	/*
	split = ft_split(str, '\'');
	int i = 0;
	while (split[i])
		printf("%s\n", split[i++]);
	*/
	get_zone(str);
	return 0;
}
