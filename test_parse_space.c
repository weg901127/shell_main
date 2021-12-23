#include "libft/libft.h"
#include <stdio.h>
#include "micro_shell.h"
char	*parse_space(char *string)
{
	char	buf[MAXLEN];
	int		i;
	int		single_q;
	int		double_q;

	i = 0;
	single_q = 0;
	double_q = 0;
	ft_memset(buf, 0, MAXLEN);
	while(*string)
	{
		if (*string == '\'')
			single_q = !single_q;
		else if (*string == '\"')
			double_q = !double_q;
		if (single_q || double_q)
			buf[i] = *string;
		else
		{
			if (*string == ' ' && *(string - 1) == ' ')
			{
				string++;
				continue;
			}
			buf[i] = *string;
		}
		i++;
		string++;
	}
	return ft_strdup(buf);
}

int main(int argc, char **argv)
{
	char	*str;
	char	*str2 = "  ";
	(void)argc;
	(void)argv;
	str = parse_space(str2);
	printf("%s\n", str);
	return 0;
}
