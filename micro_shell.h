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

# define SYNTAX_ERR		99
int	g_out_backup;

typedef struct s_storage
{
	// char		*infile_name;
	// char		*outfile_name;
	// char		***cmd_args;
	int			num_of_cmds;
	int			*pipe_fds;
	int			pipe_old;
	pid_t		*grandchild_pids;
	//char		*limiter;
	int			redirect_input;
	int			redirect_output;
	int			heredoc;
	int			append;
	int			last_exit_status;
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
int		execve_builtin(t_storage *bag, char *arg);
//void	heredoc_to_tmpfile(t_storage *info);

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
char	**split_cmd(char *str);

char	*parse_space(char *string);


char	*get_last_redirect(char *str, int target);
void	rd_heredoc(char *str);
void	my_execve(t_storage *bag, char	*str);
int		has_redirect(t_storage *bag, char *str);
void	handler_int(int signum);
void	handler_int_child(int signum);
void	handler_int_heredoc(int signum);

#endif
