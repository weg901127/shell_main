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
	while (*string)
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
	return (buf);
}

int main(int argc, char **argv)
{
	int	*buf;

	(void)argc;
	printf("%s\n", argv[1]);
	buf = get_zone(argv[1]);
	for (int i = 0 ; i < (int)ft_strlen(argv[1]) ; i++)
		printf("%d", buf[i]);
	free(buf);
	return 0;
}
