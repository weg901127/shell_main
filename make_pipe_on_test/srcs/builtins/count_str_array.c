#include "../../micro_shell.h"

int	count_str_array(char **arg_arr)
{
	int		i;

	i = 0;
	while (arg_arr[i])
		i++;
	return (i);
}