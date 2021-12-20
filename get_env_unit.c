#include "micro_shell.h"
int main()
{
	t_storage	*bag;
	bag = create_bag();
	init_bag(bag);
	init_builtin(bag);
	init_environ(bag);
	printf("%s",get_value(bag->environ, "PATH"));
}
