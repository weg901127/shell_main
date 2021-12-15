/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:36:56 by gilee             #+#    #+#             */
/*   Updated: 2021/12/15 14:09:23 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "micro_shell.h"

/*
void	run_builtin(t_bag *bag)
{
	//어떤 대단한 로직
	a = 어떤 무언가를 찾는 함수;
	if (a == ECHO_)
		//my echo 실행
	else if (a == CD_)
		//
}
*/

void	handler(int signum)
{
	if (signum != SIGINT)
		return ;
	write(STDOUT_FILENO, "\n", 1);
	if (rl_on_new_line() == -1)
		exit(1);
	rl_replace_line("", 1);
	rl_redisplay();
}

int	main(void)
{
	//int				ret;
	//char			*line;
	t_storage	*bag;

	bag = create_bag();
	init_bag(bag);
	init_builtin(bag);
	deleteArrayList(bag->builtin);
	/*
	init_rl_catch_signals();
	signal(SIGINT, handler);
	while (true)
	{
		line = readline("micro_shell> ");
		if (line)
		{
			ret = strcmp(line, "bye");
			if (ret)
				printf("output> %s\n", line);
			add_history(line);
			free(line);
			line = NULL;
			if (!ret)
				break ;
		}
		else
			return (1);
	}
	*/
	return (0);
}
