#ifndef MICRO_SHELL_H
# define MICRO_SHELL_H
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "gnl/get_next_line.h"
# include "srcs/array_list/arraylist.h"
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>

# define EXIT_SUCCESS	0
# define EXIT_FAILURE	1
# define PIPE_RD_FD		0
# define PIPE_WR_FD		1
# define STDIN_FD		0
# define STDOUT_FD		1
# define ECMD_NOT_FND	127
# define EPERMS_DND		126
# define MAXLEN			10000
# define MAX_ENVLEN		1000

typedef struct s_storage
{
	// char		*infile_name;
	// char		*outfile_name;
	// char		***cmd_args;
	int			num_of_cmds;
	int			**pipe_fds;
	pid_t		*grandchild_pids;
	//char		*limiter;
	//int			heredoc_flag;
	char		*input;
	char		**parse_buf;
	t_ArrayList	*runtime_env;
	t_ArrayList	*environ;
	t_ArrayList	*builtin;
}	t_storage;

typedef struct s_chunk_info
{
	int		chunk_count;
	int		str_count;
	int		quote_flag;
	char	delimiter;
}	t_chunk_info;

typedef enum e_startend
{
	START,
	END
}	t_startend;

typedef enum e_builtins
{
	ECHO_,
	CD_,
	PWD_,
	EXPORT_,
	UNSET_,
	ENV_,
	EXIT_
}	t_builtins;

/* pipex */
void	pipex(t_storage *bag, char **args);
void	allocate_before_fork(t_storage *bag, char **args);
char	**split_cmd(char *str);
void	redirect_fds(t_storage *bag, int idx);
void	fork_grandchild(t_storage *bag, char *arg, int idx);
void	execve_with_path(t_storage *bag, char *cmd, char *arg);
void	execve_cmd(t_storage *bag, char *arg);
void	execve_builtin(t_storage *bag, char *arg);
//void	heredoc_to_tmpfile(t_storage *info);

/* print_errors */
void	print_error(char *error_str, char *error_str2);
void	print_error_and_exit(char *error_str, char *error_str2, \
		int return_value);
void	print_execve_error_and_exit(char *error_str, char *error_str2, \
		int exit_status);

/* exit_macros */
int		wstatus(int status);
int		wifexited(int status);
int		wexitstatus(int status);
int		wifsignaled(int status);
int		wtermsig(int status);

/* wait_and_exit */
void	exit_for_child(int status);
void	wait_and_exit_for_grandchildren(t_storage info);

/* ./srcs/pipex/getpath */
bool	getpath(t_storage *bag, char ***path_res);

/* ./srcs/pipex/my_which */
char	*my_which(t_storage *bag, char *cmd);

/* ./srcs/init */
void	init_rl_catch_signals(void);

/*  */
t_storage	*create_bag(void);
void	init_bag(t_storage *bag);
void	init_builtin(t_storage *bag);
bool	is_builtin(t_storage *bag, const char *cmd);
void	init_environ(t_storage *bag);
void	init_runtime_env(t_storage *bag);
void	init_runtime_env(t_storage *bag);

/* getenviron */
char	**get_environ(t_storage *bag);

/*builtin*/
void	builtin_cd(t_storage *bag, char *arg);
void	builtin_echo(t_storage *bag, char *str);
void    builtin_env(t_storage *bag);
void	builtin_exit(t_storage *bag, char *arg);
void    builtin_export(t_storage *bag, char *arg);
void	builtin_pwd(t_storage *bag);
void    builtin_unset(t_storage *bag, char *arg);
int		count_str_array(char **arg_arr);
void	set_environ(t_storage *bag, int exit_status);
bool	strncmp_exact(char *str1, char *str2, char c);
char    *get_value(t_ArrayList *env, char *str);
void    update_env(t_ArrayList *env, char *key, char *new_val);
/* parse_master */
bool parse_master(t_storage *bag);

#endif
