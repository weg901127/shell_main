#include "micro_shell.h"
#include <assert.h>

int main()
{
	t_bag *bag;

	bag = create_bag();
	init_bag(bag);
	assert(bag != 0);

	init_builtin(bag);
	assert(bag->builtin != 0);

	/* is_builtin TEST */
	assert(is_builtin(bag, "echo") == 1);
	assert(is_builtin(bag, "cd") == 1);
	assert(is_builtin(bag, "pwd") == 1);
	assert(is_builtin(bag, "export") == 1);
	assert(is_builtin(bag, "unset") == 1);
	assert(is_builtin(bag, "env") == 1);
	assert(is_builtin(bag, "exit") == 1);
	printf("\033[32;1mDONE\n\033[m");
}
