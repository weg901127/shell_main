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
# define STDIN_FD		0
# define STDOUT_FD		1
# define MAXLEN			10000
# define MAX_ENVLEN		1000
# define SYNTEX_ERR		99
# define ERROR			100

int	g_out_backup;

typedef struct s_storage
{
	int			num_of_cmds;
	int			pipe_old;
	int			redirect_input;
	int			redirect_output;
	int			heredoc;
	int			append;
	int			last_exit_status;
	int			named[2];
	int			*location_input;
	int			*location_output;
	char		*input;
	char		**parse_buf;
	t_ArrayList	*runtime_env;
	t_ArrayList	*environ;
	t_ArrayList	*builtin;
}	t_storage;

typedef enum e_startend
{
	START,
	END
}	t_startend;

/* pipex */
void	pipex(t_storage *bag, char **args);
int		execve_builtin(t_storage *bag, char *arg);

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
int		builtin_cd(t_storage *bag, char *arg);
int		builtin_echo(char *str);
int    	builtin_env(t_storage *bag);
int		builtin_exit(t_storage *bag, char *arg);
int   	builtin_export(t_storage *bag, char *arg);
int		builtin_pwd(void);
int    	builtin_unset(t_storage *bag, char *arg);
int		count_str_array(char **arg_arr);
void	set_environ(t_storage *bag, int exit_status);
bool	strncmp_exact(char *str1, char *str2, char c);
char    *get_value(t_ArrayList *env, char *str);
void    update_env(t_ArrayList *env, char *key, char *new_val);
/* parse_master */
char	*cutnjoin(char *string, char target);
bool 	parse_master(t_storage *bag);

char	*parse_space(char *string);
char	*parse_env(t_storage *bag, char *string, int is_heredoc);


int		do_not_fork(t_storage *bag, char *str);
void	process_redirect_input(t_storage *bag, char *str);
void	process_redirect_output(t_storage *bag, char *str, int *pip);
char	*get_last_redirect(char *str, int target);
char	**split_pipe(char *str);
char	**split_echo(char *str);
int		*get_zone(char *string, int target);
char	*get_last_redirect(char *str, int target);
void	rd_heredoc(t_storage *bag, char *str, int *fd_old, int location);
void	my_execve(t_storage *bag, char	*str);
int		has_redirect(t_storage *bag, char *str);
void	handler_int(int signum);
void	handler_int_child(int signum);
void	handler_int_heredoc(int signum);
void	handler_quit(int signum);

#endif
