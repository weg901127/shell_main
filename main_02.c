/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:36:56 by gilee             #+#    #+#             */
/*   Updated: 2021/12/04 23:29:44 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "micro_shell.h"
#include "libft/libft.h"

bool	is_builtin(char *name)
{
	char	builtin[7][6];
	int		i;

	i = 7;
	builtin = {"echo", "cd", "pwd", "export", "unset", "env", "exit"};
	ft_memcpy(builtin[0], "echo", sizeof(char) * 4);
	while(i--)
	{
		if (ft_strncmp(const char *s1, const char *s2, size_t n))
	}

}
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
	int				ret;
	char			*line;

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
	return (0);
}
