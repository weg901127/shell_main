/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:29:08 by sehhong           #+#    #+#             */
/*   Updated: 2021/09/27 10:58:55 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define EXIT_FAILURE	1
# define EXIT_SUCCESS	0
# define INFILE_INDEX	1
# define COMMAND1_INDEX	2
# define COMMAND2_INDEX	3
# define OUTFILE_INDEX	4
# define ECMD_NOT_FND	127
# define EPERMS_DND		126
# define STDIN_FD		0
# define STDOUT_FD		1
# define PIPE_RD_FD		0
# define PIPE_WR_FD		1

# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <sys/errno.h>

typedef struct s_storage
{
	char	*infile_name;
	char	*outfile_name;
	char	**cmd1_arg;
	char	**cmd2_arg;
	int		pipe_fds[2];
	pid_t	pids[2];
}				t_storage;

typedef struct s_chunk_info
{
	int		chunk_count;
	int		str_count;
	int		quote_flag;
	char	delimiter;
}				t_chunk_info;

/*parse_argument, split_cmd*/
void	parse_arguments(t_storage *arg_arr, int argc, char **argv);
char	**split_cmd(char *str);

/*print_errors*/
void	print_error(char *error_str, char *error_str2);
void	print_error_and_exit(char *error_str, char *error_str2, \
		int return_value);
void	print_execve_error_and_exit(char *error_str, char *error_str2, \
		int exit_status);

/*redirect_fds*/
void	redirect_fds_in_1st_grandchild(t_storage *info);
void	redirect_fds_in_2nd_grandchild(t_storage *info);

/*fork_grandchildren*/
void	fork_1st_grandchild(t_storage *info, char **envp);
void	fork_2nd_grandchild(t_storage *info, char **envp);

/*execve_with_path*/
char	**split_path_env(char **envp);
void	execve_with_path(char **path_list, char **cmd_arg, char **envp);
void	execve_with_error_handling(char **array_of_path, char **cmd_arg, \
	char **envp, char *final_path);

/*exit_macros*/
int		wstatus(int status);
int		wifexited(int status);
int		wexitstatus(int status);
int		wifsignaled(int status);
int		wtermsig(int status);

/*wait_and_exit*/
void	exit_for_child(int status);
void	wait_and_exit_for_grand_children(t_storage info);

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

#endif
