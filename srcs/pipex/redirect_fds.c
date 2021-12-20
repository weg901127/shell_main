#include "../../micro_shell.h"

void	redirect_fds_in_1st_grandchild(t_storage *info)
{
	int	infile_fd;

	if ((access(info->infile_name, R_OK)) == -1)
		print_error_and_exit(strerror(errno), info->infile_name, -1);
	infile_fd = open(info->infile_name, O_RDONLY);
	print_error_and_exit("open() has failed", NULL, infile_fd);
	print_error_and_exit("dup2() has failed", NULL, dup2(infile_fd, STDIN_FD));
	close(infile_fd);
	print_error_and_exit("dup2() has failed", NULL, \
		dup2(info->pipe_fds[0][PIPE_WR_FD], STDOUT_FD));
	close(info->pipe_fds[0][PIPE_WR_FD]);
}

void	redirect_fds_in_nth_grandchild(t_storage *info, int cmd_idx)
{
	print_error_and_exit("dup2() has failed", NULL, \
		dup2(info->pipe_fds[cmd_idx - 1][PIPE_RD_FD], STDIN_FD));
	close(info->pipe_fds[cmd_idx - 1][PIPE_RD_FD]);
	print_error_and_exit("dup2() has failed", NULL, \
		dup2(info->pipe_fds[cmd_idx][PIPE_WR_FD], STDOUT_FD));
	close(info->pipe_fds[cmd_idx][PIPE_WR_FD]);
}

void	redirect_fds_in_last_grandchild(t_storage *info)
{
	int	outfile_fd;
	int	last_pipe_idx;

	last_pipe_idx = info->num_of_cmds - 2;
	print_error_and_exit("dup2() has failed", NULL, \
		dup2(info->pipe_fds[last_pipe_idx][PIPE_RD_FD], STDIN_FD));
	close(info->pipe_fds[last_pipe_idx][PIPE_RD_FD]);
	if (((access(info->outfile_name, W_OK)) == -1) && errno == EACCES)
		print_error(strerror(errno), info->outfile_name);
	if (info->heredoc_flag == 0)
		outfile_fd = open(info->outfile_name, O_WRONLY | O_CREAT | O_TRUNC, \
			0644);
	else
		outfile_fd = open(info->outfile_name, O_WRONLY | O_CREAT | O_APPEND, \
			0644);
	print_error_and_exit("open() has failed", info->outfile_name, outfile_fd);
	print_error_and_exit("dup2() has failed", NULL, \
		dup2(outfile_fd, STDOUT_FD));
	close(outfile_fd);
}
