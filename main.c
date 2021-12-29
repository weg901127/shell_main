#include "libft/libft.h"
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
	write(g_out_backup, "\n", 1);
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

//sehhong: readline 시리즈 이유!

int	main(void)
{
	char			*line;
	t_storage		*bag;

	g_out_backup = dup(1);
	bag = create_bag();
	init_bag(bag);
	init_builtin(bag);
	init_environ(bag);
	init_runtime_env(bag);
	
	init_rl_catch_signals();
	signal(SIGINT, handler_int);
	while (true)
	{
		line = readline("micro_shell> ");
		if (line)
		{
			bag->input = ft_strdup(line);
			parse_master(bag);
			add_history(line);
			free(line);
			free(bag->input);
			line = NULL;
		}
		//sehhong: 이부분이 어떻게 쓰이는거지?
		usleep(10000);
		//sehhong: g_out_backup의 용도 확인: stdout를 나중에 원상복귀 시키기 위해?!
		dup2(g_out_backup, 1);
		//else
		//	return (1);
		//sehhong: micro_shell> exit 했을 때 minishell 끝내기 with exit(0);
	}
	
	return (0);
}


