#include "libft/libft.h"
#include <stdio.h>
#define MAXLEN 10000
int	*get_zone(char *string, int target)
{
	int	*buf;
	int	start;
	int	i;

	i = 0;
	start = 0;
	buf = (int *)ft_calloc(ft_strlen(string), sizeof(int));
	while (*string)
	{
		if (*string == target)
		{
			buf[i] = 2;
			if (ft_strchr(string + 1, target))
				start = !start;
			else if (!ft_strchr(string + 1, target))
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
	(void)argc;
	(void)argv;
	char	**res;
	int	i = 0;
	res = split_pipe("echo \"cat|cat|ls\"");
	while (res[i])
		printf("%s\n", res[i++]);
}
