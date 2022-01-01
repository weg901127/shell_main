#include "../../micro_shell.h"

static int		is_special(char **str)
{
	int	res;

	res = 0;
	res |= (ft_strlen(str[0]) == 6
			&& !ft_strncmp(str[0], "export", 6)
			&& !(ft_strchr(str[1], '<') || ft_strchr(str[1], '>'))
			&& ft_strlen(str[1]));
	res |= (ft_strlen(str[0]) == 3 && !ft_strncmp(str[0], "env", 3));
	res |= (ft_strlen(str[0]) == 5 && !ft_strncmp(str[0], "unset", 5));
	res |= (ft_strlen(str[0]) == 4 && !ft_strncmp(str[0], "exit", 4));
	res |= (ft_strlen(str[0]) == 2 && !ft_strncmp(str[0], "cd", 2));
	return (res);
}

int		do_not_fork(t_storage *bag, char *str)
{
	char	**split;

	split = ft_split(str, ' ');
	if (bag->num_of_cmds == 1 && is_special(split))
		return (1);
	return (0);
}
