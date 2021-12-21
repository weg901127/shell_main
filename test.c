#include "libft/libft.h"
#include "micro_shell.h"
#include "srcs/array_list/arraylist.h"
#include <assert.h>
#include <sys/_types/_pid_t.h>
#include <unistd.h>

// void	print_all_env(t_storage *bag)
// {
// 	int	i;

// 	i = 0;
// 	while (i < bag->environ->current_element_count)
// 	{
// 		printf("%s\n", getALElement(bag->environ, i)->data);
// 		i++;
// 	}
// }
/*
extern char **environ;
int	main(void)
{
	t_storage	*bag;
	bag = create_bag();
	init_bag(bag);
	init_builtin(bag);
	init_environ(bag);
	init_runtime_env(bag);
	print_all_env(bag);
	printf("-----------------------------------");
	printf("\033[32;1mDONE\n\033[m");
}
*/
////////////////



// int	main(void)
// {
// 	t_storage	*bag;
// 	bag = create_bag();
// 	init_bag(bag);
// 	init_builtin(bag);
// 	init_environ(bag);
// 	init_runtime_env(bag);
// 	builtin_cd(bag, "srcs a b c d e");
// 	printf("%s\n", get_value(bag->runtime_env, "?"));
// 	builtin_pwd(bag);
// 	printf("%s\n", get_value(bag->runtime_env, "?"));
// 	printf("----------------------------------------------------------\n");
// 	builtin_env(bag);
// 	printf("----------------------------------------------------------\n");
// 	printf("%s\n", get_value(bag->runtime_env, "?"));
// 	builtin_exit(bag, "11 12 13 14 15");
// 	printf("%s\n", get_value(bag->runtime_env, "?"));
// 	builtin_export(bag, "water=haha asdf=hihi fdsa");
// 	printf("%s\n", get_value(bag->runtime_env, "?"));
// 	printf("----------------------------------------------------------\n");
// 	builtin_env(bag);
// 	printf("----------------------------------------------------------\n");
// 	printf("%s\n", get_value(bag->runtime_env, "?"));
// 	builtin_unset(bag, "water aa");
// 	printf("%s\n", get_value(bag->runtime_env, "?"));
// 	printf("----------------------------------------------------------\n");
// 	builtin_env(bag);
// 	printf("----------------------------------------------------------\n");
// 	printf("%s\n", get_value(bag->runtime_env, "?"));
// 	builtin_echo(bag, "HAKLSDJFLKAJSDL GJLKSJaslkdjflkj gjlk", 0);
// 	printf("%s\n", get_value(bag->runtime_env, "?"));
// 	printf("\033[32;1mDONE\n\033[m");
// 	while (1);
// }


int	main(void)
{
	t_storage	*bag;
	t_ArrayListNode	element;

	bag = create_bag();
	init_bag(bag);
	init_builtin(bag);
	init_environ(bag);
	init_runtime_env(bag);
	element.data = "water=huhu";
	addALElement(bag->runtime_env, bag->runtime_env->current_element_count, element);
	printf("water = %s\n", get_value(bag->runtime_env, "water"));
	builtin_export(bag, "asdf=hihi fdsa=haha qwer rewq");
	builtin_export(bag, "=hihih asdf=yum_yum water");
	builtin_unset(bag, "asdf");
	builtin_env(bag);
	builtin_unset(bag, "water");
	printf("%s\n", get_value(bag->runtime_env, "?"));
	builtin_env(bag);
	printf("\033[32;1mDONE\n\033[m");
	while (1);
}