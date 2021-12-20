#include "../../micro_shell.h"

void	init_bag(t_storage *bag)
{
	bag->builtin = createArrayList(7);
	bag->environ = createArrayList(30);
	bag->runtime_env = createArrayList(30);
}
