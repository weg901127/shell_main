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
// 	char	str[] = "hellohello";
// 	char	cmp_str[] = "hellohell";

// 	printf("%d\n", ft_strncmp(str, cmp_str, ft_strlen(cmp_str)));
// 	return(0);
// }
