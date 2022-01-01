#include "../../micro_shell.h"

char	*get_last_redirect(char *str, int target)
{
	char	*buf;
	char	*res;

	res = NULL;
	buf = str;
	while (buf)
	{
		buf = ft_strchr(buf, target);
		if (buf)
		{
			res = buf;
			buf = buf + 1;
		}
	}
	return res;
}
