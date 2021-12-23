#include "../../micro_shell.h"

void	init_runtime_env(t_storage *bag)
{
	t_ArrayListNode element;
    
    element.data = ft_strjoin("0=", "microshell");
    addALElement(bag->runtime_env, bag->runtime_env->current_element_count, element);
    element.data = ft_strjoin("?=", "0");
    addALElement(bag->runtime_env, bag->runtime_env->current_element_count, element);
}

