#include "../../micro_shell.h"

bool	is_builtin(t_storage *bag, const char *cmd)
{
	bool	res;
	int		i;
	char	*tmp;

	res = false;
	i = bag->builtin->current_element_count;
	while (i--)
	{
		tmp = getALElement(bag->builtin, i)->data;
		if (!ft_strncmp(cmd, tmp, ft_strlen(tmp)))
			res = true;
	}
	return (res);
}
