#include "micro_shell.h"
#include "srcs/array_list/arraylist.h"
#include <assert.h>
#include <sys/_types/_pid_t.h>
#include <unistd.h>
// extern char **environ;
// int main(int argc, char **argv)
// {
// 	t_storage	*bag;
// 	int			i;
// 	//char		*arr[3] = {
// 	//	"ls",
// 	//};
// 	//pid_t		pid;

// 	i = 0;
// 	(void)argc;
// 	(void)argv;
// 	bag = create_bag();
// 	init_bag(bag);
// 	assert(bag != 0);

	
// 	init_builtin(bag);
// 	assert(bag->builtin != 0);

// 	assert(is_builtin(bag, "echo") == 1);
// 	assert(is_builtin(bag, "cd") == 1);
// 	assert(is_builtin(bag, "pwd") == 1);
// 	assert(is_builtin(bag, "export") == 1);
// 	assert(is_builtin(bag, "unset") == 1);
// 	assert(is_builtin(bag, "env") == 1);
// 	assert(is_builtin(bag, "exit") == 1);
		
// 	init_environ(bag);
// 	i = 0;
// 	while (i < bag->environ->currentElementCount)
// 	{
// 		printf("%s\n",  getALElement(bag->environ, i)->data);
// 		i++;
// 	}
	

// 	printf("\033[32;1mDONE\n\033[m");
// }

extern char **environ;
int	main(void)
{
	t_storage	*bag;
	char		**cmd_arg;
	int			i;

	bag = create_bag();
	init_bag(bag);
	init_environ(bag);
	cmd_arg = getenviron(bag);
	i = 0;
	while (cmd_arg[i])
	{
		printf("%s\n", cmd_arg[i]);
		i++;
	}
	printf("\033[32;1mDONE\n\033[m");
}
