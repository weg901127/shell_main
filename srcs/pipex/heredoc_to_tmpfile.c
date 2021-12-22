#include "../../micro_shell.h"

// void	heredoc_to_tmpfile(t_storage *info)
// {
// 	int		tmp_fd;
// 	char	*line;
// 	char	*tmp_str;
// 	size_t	limiter_len;

// 	limiter_len = ft_strlen(info->limiter);
// 	info->infile_name = ".temporary";
// 	tmp_fd = open(info->infile_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	print_error_and_exit("open() has failed", info->infile_name, tmp_fd);
// 	while (1)
// 	{
// 		ft_putstr_fd("pipe heredoc> ", STDOUT_FD);
// 		get_next_line(STDIN_FD, &line);
// 		if (limiter_len == ft_strlen(line) && \
// 			(!ft_strncmp(line, info->limiter, limiter_len)))
// 			break ;
// 		tmp_str = ft_strjoin(line, "\n");
// 		ft_putstr_fd(tmp_str, tmp_fd);
// 		ft_ptr_free(tmp_str);
// 		ft_ptr_free(line);
// 		line = NULL;
// 	}
// 	ft_ptr_free(line);
// 	close(tmp_fd);
// }
