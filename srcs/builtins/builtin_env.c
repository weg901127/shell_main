#include "../../micro_shell.h"

int builtin_env(t_storage *bag)
{
    int     i;
    char    *data;
    
    i = 0;
    while (i < bag->environ->current_element_count)
    {
        data = getALElement(bag->environ, i)->data;
        ft_putendl_fd(data, STDOUT_FD);
        i++;
    }
    return (EXIT_SUCCESS);
}