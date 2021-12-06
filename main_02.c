/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:36:56 by gilee             #+#    #+#             */
/*   Updated: 2021/12/06 21:39:29 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "micro_shell.h"

t_bag	*create_bag()
{
	return ((t_bag *)ft_calloc(1, sizeof(t_bag)));
}

void	init_bag(t_bag *bag)
{
	bag->builtin = createArrayList(7);
}

void	init_builtin(t_bag *bag)
{
	int				fd;
	char			*buf;
	t_ArrayListNode	element;

	fd = open("./.builtin", O_RDONLY);
	while (1)
	{
		get_next_line(fd, &buf);
		element.data = buf;
		if(*buf == 0)
			break;
		addALElement(bag->builtin, 0, element);
	}
}

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

int		main(void)
{
	//int				ret;
	//char			*line;
	t_bag			*bag;

	bag = create_bag();
	init_bag(bag);
	init_builtin(bag);
	printf("%s\n", getALElement(bag->builtin, 0)->data);
	
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
