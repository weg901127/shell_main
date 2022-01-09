#include "../../micro_shell.h"

static void	my_free(char ***arg_arr)
{
	int	i;

	i = 0;
	while ((*arg_arr)[i])
		free((*arg_arr)[i++]);
	free(*arg_arr);
}

static void	change_pwds_environ(t_storage *bag, char *curr_pwd, char *new_path)
{
	t_ArrayListNode	element;

	if (!get_value(bag->environ, "OLDPWD"))
	{	
		element.data = ft_strjoin("OLDPWD=", curr_pwd);
		addALElement(bag->environ,
			bag->environ->current_element_count - 1, element);
	}
	else
		update_env(bag->environ, "OLDPWD", curr_pwd);
	update_env(bag->environ, "PWD", new_path);
}

int	builtin_cd(t_storage *bag, char *arg)
{
	char	**arg_arr;
	char	*path;
	int		exit_status;

	exit_status = EXIT_SUCCESS;
	arg_arr = ft_split(arg, ' ');
	if (arg_arr[0] == NULL)
		path = get_value(bag->environ, "HOME");
	else
		path = arg_arr[0];
	if (chdir(path) == -1)
	{
		ft_print_error("cd", path, strerror(errno));
		exit_status = EXIT_FAILURE;
	}
	else
		change_pwds_environ(bag, get_value(bag->environ, "PWD"), path);
	my_free(&arg_arr);
	return (exit_status);
}
