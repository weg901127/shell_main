#include "../../micro_shell.h"

static void	str_malloc_and_insert(char **cmd, char *str, int len, int index)
{
	cmd[index] = (char *)ft_calloc(len + 1, sizeof(char));
	ft_memcpy(cmd[index], str, len);
}

char	**get_environ(t_storage *bag)
{
	char	**ret;
	int		i;
	char	*tmp_data;

	ret = (char **)malloc
		((bag->environ->current_element_count + 1) * sizeof(char *));
	i = 0;
	while (i < bag->environ->current_element_count)
	{
		tmp_data = getALElement(bag->environ, i)->data;
		str_malloc_and_insert(ret, tmp_data, ft_strlen(tmp_data), i);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
