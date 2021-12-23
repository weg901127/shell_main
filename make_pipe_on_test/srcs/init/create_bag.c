#include "../../micro_shell.h"

t_storage	*create_bag(void)
{
	return ((t_storage *)ft_calloc(1, sizeof(t_storage)));
}
