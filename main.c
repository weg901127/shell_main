#include <unistd.h>
#include "libft/libft.h"
#include "micro_shell.h"


static void	init(t_storage *bag)
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
				free(line);
				continue;
			}
			bag->input = ft_strdup(line);
			parse_master(bag);
			add_history(line);
			free(line);
			free(bag->input);
			free(buf);
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
