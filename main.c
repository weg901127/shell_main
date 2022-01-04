#include <unistd.h>
#include "micro_shell.h"

void	handler_int(int signum)
{
	if (signum != SIGINT)
		return ;
	write(STDOUT_FILENO, "\n", 1);
	if (rl_on_new_line() == -1)
		exit(1);
	rl_replace_line("", 1);
	rl_redisplay();
}

void	handler_int_child(int signum)
{
	if (signum != SIGINT)
		return ;
	exit(SIGINT);
}

void	handler_int_heredoc(int signum)
{
	if (signum != SIGINT)
		return ;
	write(STDOUT_FILENO, "\n", 1);
	if (rl_on_new_line() == -1)
		exit(1);
	rl_replace_line("", 1);
	rl_redisplay();
}

void	init(t_storage *bag)
{
	init_bag(bag);
	init_builtin(bag);
	init_environ(bag);
	init_runtime_env(bag);
	init_rl_catch_signals();
	bag->named[0] = dup(0);
	bag->named[1] = dup(1);
	signal(SIGINT, handler_int);
	signal(SIGQUIT, SIG_IGN);
}

int	main(void)
{
	char		*line;
	char		*buf;
	t_storage	*bag;

	g_out_backup = dup(1);
	bag = create_bag();
	init(bag);
	while (true)
	{
		line = readline("micro_shell> ");
		if (line)
		{
			buf = ft_strtrim(line, " ");
			if (!(*buf))
			{
				free(buf);
				continue;
			}
			bag->input = ft_strdup(line);
			parse_master(bag);
			add_history(line);
			free(line);
			free(bag->input);
			line = NULL;
		}
		else
		{
			printf ("micro_shell> exit");
			exit(0);
		}
	}
	return (0);
}
