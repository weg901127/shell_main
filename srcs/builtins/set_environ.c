#include "../../micro_shell.h"

void	set_environ(t_storage *bag, int exit_status)
{
	char	*data;
	char	*buf;

	data = getALElement(bag->runtime_env, 1)->data;
	free(data);
	data = NULL;
	buf = ft_itoa(exit_status);
	(getALElement(bag->runtime_env, 1)->data) = ft_strjoin("?=", buf);
	free(buf);
	buf = NULL;
}
