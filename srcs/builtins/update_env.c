#include "../../micro_shell.h"

static	void	add_env(t_ArrayList *env, char *key, char *new_val)
{
	t_ArrayListNode	element;
	char			*tmp;

	tmp = key;
	if (ft_strlen(new_val))
		tmp = ft_strjoin(key, "=");
	element.data = ft_strjoin(tmp, new_val);
	if (ft_strlen(new_val))
		free(tmp);
	tmp = NULL;
	addALElement(env, env->current_element_count, element);
}

void    update_env(t_ArrayList *env, char *key, char *new_val)
{
    int		i;
	char	*data;
    char    *tmp;

	i = 0;
	tmp = key;
	while (i < env->current_element_count)
	{
		data = getALElement(env, i)->data;
		if (strncmp_exact(data, key, '='))
		{
            free(data);
			data = NULL;
			if (ft_strlen(new_val))
            	tmp = ft_strjoin(key, "=");
            data = ft_strjoin(tmp, new_val);
			if (ft_strlen(new_val))
				free(tmp);
			tmp = NULL;
			getALElement(env, i)->data = data;
			return ;
		}
        i++;
	}
	if (i == env->current_element_count)
		add_env(env, key, new_val);
}
