#include "../../micro_shell.h"

//TODO err code 확인하기!
static void	change_pwds_environ(t_storage *bag, char *curr_pwd, char *new_path)
{
	t_ArrayListNode	element;

	if (!get_value(bag->environ, "OLDPWD"))
	{	
		element.data = ft_strjoin("OLDPWD=", curr_pwd);
		addALElement(bag->environ, bag->environ->current_element_count - 1, element);
	}
	else
		update_env(bag->environ, "OLDPWD", curr_pwd);
	update_env(bag->environ, "PWD", new_path);
}

void	builtin_cd(t_storage *bag, char *arg)
{
	char	**arg_arr;
	char	*path;

	arg_arr = split_cmd(arg);
	if (arg_arr[0] == NULL)
		path = get_value(bag->environ, "HOME");
	else
		path = arg_arr[0];
	if (chdir(path) == -1)
	{
		ft_print_error("cd", path, strerror(errno));
		set_environ(bag, EXIT_FAILURE);
	}
	else
	{
		set_environ(bag, EXIT_SUCCESS);
		change_pwds_environ(bag, get_value(bag->environ, "PWD"), path);
	}
}