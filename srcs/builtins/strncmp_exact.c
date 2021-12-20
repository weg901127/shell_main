#include "../../micro_shell.h"

bool	strncmp_exact(char *str1, char *str2, char c)
{
	int	len_str2;

	len_str2 = ft_strlen(str2);
	if (!ft_strncmp(str1, str2, len_str2) && str1[len_str2] == c)
		return (TRUE);
	return (FALSE);
}
