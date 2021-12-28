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
//
/*
int		has_redirect(t_storage *bag, char *str)
{
	int		res;
	char	*buf;

	res = 0;
	buf = str;
	while (buf != NULL)
	{
		buf = ft_strchr(buf, '<');
		if (buf && buf[0] == '<' && buf[1] != '<')
		{
			bag->redirect_input = 1;
			res |= 1;
		}
		else if (buf && buf[0] == '<' && buf[1] == '<')
		{
			bag->heredoc = 1;
			res |= 1;
		}
	}
	buf = str;
	while (buf != NULL)
	{
		buf = ft_strchr(str, '>');
		if (buf && buf[0] == '>' && buf[1] != '>')
		{
			bag->redirect_output = 1;
			res |= 1;
		}
		else if (buf && buf[0] == '>' && buf[1] == '>')
		{
			bag->append = 1;
			res |= 1;
		}
	}
	return (res);
}
*/

int	main(void)
{
	t_storage	*bag;
	bag = create_bag();
	init_bag(bag);
	init_builtin(bag);
	init_environ(bag);
	init_runtime_env(bag);
	char *str = "ls <";
	has_redirect(bag, str);
	printf("\033[32;1mDONE\n\033[m");
}
