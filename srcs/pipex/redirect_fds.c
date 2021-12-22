#include "../../micro_shell.h"

void	redirect_fds(t_storage *bag, int idx)
{
	// char	*input_name;
	// char	*output_name;
	// int		input_fd;
	// int		output_fd;

	//save all info related to rdr and filter the str from the arg
	//get_rdr_from_str();
	// -> arg에는 "cmd + arguments"만 남아있음.

	//(default) connecting both pipes & closing unneccessary pipe_rd/wr
	if (idx != 0)
	{	
		print_error_and_exit("dup2() has failed", NULL, \
			dup2(bag->pipe_fds[idx - 1][PIPE_RD_FD], STDIN_FD));
		close(bag->pipe_fds[idx - 1][PIPE_RD_FD]);
	}
	if (idx != bag->num_of_cmds - 1)
	{
		print_error_and_exit("dup2() has failed", NULL, \
			dup2(bag->pipe_fds[idx][PIPE_WR_FD], STDOUT_FD));
		close(bag->pipe_fds[idx][PIPE_WR_FD]);
	}
	//depending on the mode (0 ~ 3), redirction to input_fd & output_fd
	// input_fd = open(input_name, O_RDONLY);
	// print_error_and_exit(strerror(errno), input_name, input_fd);
	// print_error_and_exit("dup2() has failed", NULL, dup2(input_fd, STDIN_FD));
	// close(input_fd);
	// if (((open(output_name, W_OK)) == -1) && errno == EACCES)
	// 	print_error(strerror(errno), output_name);
	// //>>일 경우, 추가 필요 (O_TRUNC -> O_APPEND)
	// output_fd = open(output_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	// print_error_and_exit(strerror(errno), output_name, output_fd);
	// print_error_and_exit("dup2() has failed", NULL, dup2(output_fd, STDOUT_FD));
	// close(output_fd);
}
