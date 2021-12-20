#include "../../micro_shell.h"

//쉘변수: $0=bash, $?=마지막 커맨드 exit status, $$=현재 bash쉘의 pid
void	init_runtime_env(t_storage *bag)
{
	t_ArrayListNode element;
    
    element.data = "0=microshell";
    addALElement(bag->runtime_env, bag->runtime_env->current_element_count, element);
    element.data = "?=0";
    addALElement(bag->runtime_env, bag->runtime_env->current_element_count, element);
}

