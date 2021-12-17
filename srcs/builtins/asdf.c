#include "../../micro_shell.h"

char    *get_value(t_ArrayList *env, char *str)
{
    int     i;
    int     len_str;
    char    *data;

    i = 0;
    len_str = ft_strlen(str);
    while (i < env->current_element_count)
    {
        data = getALElement(env, i)->data;
        if (!ft_strncmp(data, str, len_str) && data[len_str] == '-')
            return (data + len_str + 1);
        i++;
        return (NULL);
    }
}

