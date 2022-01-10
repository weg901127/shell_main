/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:14:02 by gilee             #+#    #+#             */
/*   Updated: 2022/01/10 13:21:05 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static int	is_null(char *buf, char *line)
{
	int	res;

	res = 0;
	if (!(*buf))
	{
		free(buf);
		free(line);
		res = 1;
	}
	return (res);
}

int	main(void)
{
	char		*line;
	char		*buf;
	t_storage	*bag;

	bag = create_bag();
	init(bag);
	while (true)
	{
		line = readline("micro_shell> ");
		if (line)
		{
			buf = ft_strtrim(line, " ");
			if (is_null(buf, line))
				continue ;
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
