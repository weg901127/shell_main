#include "../../micro_shell.h"

void	print_error(char *error_str, char *error_str2)
{
	ft_putstr_fd("micro_shell: ", 2);
	ft_putstr_fd(error_str, 2);
	if (error_str2 != NULL)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(error_str2, 2);
	}
	ft_putstr_fd("\n", 2);
}

void	print_error_and_exit(char *error_str, char *error_str2, \
	int return_value)
{
	if (return_value == -1)
	{
		print_error(error_str, error_str2);
		exit(EXIT_FAILURE);
	}
}

void	print_execve_error_and_exit(char *error_str, char *error_str2, \
	int exit_status)
{
	print_error(error_str, error_str2);
	exit(exit_status);
}
