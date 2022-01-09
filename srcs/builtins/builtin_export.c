#include "../../micro_shell.h"

static int	where_is_equal(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-2);
	while (str[i])
	{
		if (str[i] == '=')
			return (i);
		i++;
	}
	return (-1);
}

static void	export_no_option(t_storage *bag)
{
	int	i;

	i = 0;
	while (i < bag->environ->current_element_count)
	{
		ft_putstr_fd("declare -x ", STDOUT_FD);
		ft_putendl_fd(getALElement(bag->environ, i)->data, STDOUT_FD);
		i++;
	}
}

static void	add_name_on_env(t_storage *bag, char *key_value, int equal_here)
{
	char			key[10000];
	t_ArrayListNode	element;

	ft_memccpy(key, key_value, '=', equal_here);
	key[equal_here] = '\0';
	if (get_value(bag->environ, key))
		update_env(bag->environ, key, key_value + equal_here + 1);
	else
	{
		element.data = ft_strdup(key_value);
		addALElement(bag->environ,
			bag->environ->current_element_count, element);
	}
}

static void	export_core(t_storage *bag, char **arg_arr, int *exit_status)
{
	int	i;
	int	equal_here;

	i = 0;
	equal_here = 0;
	if (arg_arr[0] == NULL || *arg_arr[0] == '#')
		export_no_option(bag);
	else
	{
		while (arg_arr[i])
		{
			equal_here = where_is_equal(arg_arr[i]);
			if (!equal_here)
			{
				ft_print_error("export", arg_arr[i], "not a valid identifier");
				*exit_status = EXIT_FAILURE;
			}
			else if (equal_here == -1)
				update_env(bag->environ, arg_arr[i],
					get_value(bag->runtime_env, arg_arr[i]));
			else
				add_name_on_env(bag, arg_arr[i], equal_here);
			i++;
		}
	}
}

int	builtin_export(t_storage *bag, char *arg)
{
	char	**arg_arr;
	int		exit_status;

	exit_status = EXIT_SUCCESS;
	arg_arr = ft_split(arg, ' ');
	export_core(bag, arg_arr, &exit_status);
	ft_malloc_fail_str(arg_arr, count_str_array(arg_arr));
	return (exit_status);
}
