#include "../../micro_shell.h"

//runtime_env의 요소중 $0, $?를 정해진 위치에 두면 좋을 듯.
void	set_environ(t_storage *bag, int exit_status)
{
	//$?의 고정된 위치에 따라 position(1)을 바꿀 것!
	char	*data;

	data = getALElement(bag->runtime_env, 1)->data;
	free(data);
	data = NULL;
	getALElement(bag->runtime_env, 1)->data = ft_itoa(exit_status);
}
