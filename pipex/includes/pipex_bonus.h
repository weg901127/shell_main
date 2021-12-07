/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 08:28:44 by sehee             #+#    #+#             */
/*   Updated: 2021/09/27 10:59:18 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# define EXIT_SUCCESS	0
# define EXIT_FAILURE	1
# define PIPE_RD_FD		0
# define PIPE_WR_FD		1
# define STDIN_FD		0
# define STDOUT_FD		1
# define ECMD_NOT_FND	127
# define EPERMS_DND		126

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	100
# endif

# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <limits.h>
# include <string.h>

typedef struct s_storage
{
	char	*infile_name;
	char	*outfile_name;
	char	***cmd_args;
	int		num_of_cmds;
	int		**pipe_fds;
	pid_t	*grandchild_pids;
	char	*limiter;
	int		heredoc_flag;
}				t_storage;

typedef struct s_chunk_info
{
	int		chunk_count;
	int		str_count;
	int		quote_flag;
	char	delimiter;
}				t_chunk_info;

/*parse_arguments_bonus, parse_arguments2_bonus, split_cmd_bonus*/
void	parse_arguments_for_heredoc(int argc, char **argv, t_storage *info);
void	parse_arguments_for_multi_pipes(t_storage *info, int argc, char **argv);
void	parse_arguments(int argc, char **argv, t_storage *info);
void	malloc_grandchild_pids(t_storage *info);
void	malloc_pipe_fds(t_storage *info);
void	malloc_cmd_args(t_storage *info, char **argv);
char	**split_cmd(char *str);

/*get_next_line_bonus*/
int		get_next_line(int fd, char **line);

/*heredoc_to_tmpfile_bonus*/
void	heredoc_to_tmpfile(t_storage *info);

/*print_errors_bonus*/
void	print_error(char *error_str, char *error_str2);
void	print_error_and_exit(char *error_str, char *error_str2, \
		int return_value);
void	print_execve_error_and_exit(char *error_str, char *error_str2, \
		int exit_status);

/*libft*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_malloc_fail_str(char **str, int max);
void	ft_malloc_fail_int(int **arr, int max);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_tolower(int c);
void	ft_ptr_free(char *ptr);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
void	ft_strncpy(char *dst, char const *src, size_t src_len);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	**ft_split(char *str, char c);
void	*ft_memset(void *b, int c, size_t len);
void	ft_strcopy_with_delimiter(char *dest, char *src, char c);

/*redirect_fds_bonus*/
void	redirect_fds_in_1st_grandchild(t_storage *info);
void	redirect_fds_in_nth_grandchild(t_storage *info, int cmd_idx);
void	redirect_fds_in_last_grandchild(t_storage *info);

/*fork_grandchildren_bonus*/
void	fork_1st_grandchild(t_storage *info, char **envp);
void	fork_nth_grandchild(t_storage *info, int cmd_idx, char **envp);
void	fork_last_grandchild(t_storage *info, char **envp);

/*execve_with_path_bonus*/
void	execve_with_path(char **array_of_path, char **cmd_arg, char **envp);
char	**split_path_env(char **envp);
void	execve_with_error_handling(char **array_of_path, char **cmd_arg, \
	char **envp, char *final_path);

/*exit_macros_bonus*/
int		wstatus(int status);
int		wifexited(int status);
int		wexitstatus(int status);
int		wifsignaled(int status);
int		wtermsig(int status);

/*wait_and_exit_bnous*/
void	exit_for_child(int status);
void	wait_and_exit_for_grandchildren(t_storage info);

#endif
