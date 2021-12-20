#include "../../micro_shell.h"

void    update_env(t_ArrayList *env, char *key, char *new_val)
{
    int		i;
	char	*data;
    char    *tmp;
    int     len_key;

	i = 0;
    len_key = ft_strlen(key);
	while (i < env->current_element_count)
	{
		data = getALElement(env, i)->data;
		if (strncmp_exact(data, key, '='))
		{
            free(data);
			data = NULL;
            tmp = ft_strjoin(key, "=");
            data = ft_strjoin(tmp, new_val);
			free(tmp);
			tmp = NULL;
			getALElement(env, i)->data = data;
			return ;
		}
        i++;
	}
}
