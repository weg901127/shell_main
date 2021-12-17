#include <stdio.h>
#include "libft/libft.h"
#include "micro_shell.h"
#include "srcs/array_list/arraylist.h"

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
