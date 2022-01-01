#include "../../micro_shell.h"

void	skip_space(char *buf, char **string, int i)
{
	if (**string == ' ' && *(*string - 1) == ' ')
	{
		(*string)++;
		return ;
	}
	buf[i] = **string;
}

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
	while (*string)
	{
		if (*string == '\'')
			single_q = !single_q;
		else if (*string == '\"')
			double_q = !double_q;
		if (single_q || double_q)
			buf[i] = *string;
		else
			skip_space(buf, &string, i);
		i++;
		string++;
	}
	return (ft_strdup(buf));
}
