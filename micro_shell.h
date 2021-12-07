/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_shell.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 19:46:02 by gilee             #+#    #+#             */
/*   Updated: 2021/12/07 13:38:21 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICRO_SHELL_H
# define MICRO_SHELL_H
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdio.h>
#include <fcntl.h>
# include "gnl/get_next_line.h"
# include "srcs/array_list/arraylist.h"

typedef	enum e_builtins
{
	ECHO_,
	CD_,
	PWD_,
	EXPORT_,
	UNSET_,
	ENV_,
	EXIT_
}	t_builtins;

typedef struct s_bag
{
	t_ArrayList	*builtin;
}	t_bag;

/* ./srcs/init */
void	init_rl_catch_signals();

/*  */
t_bag	*create_bag();
void	init_bag(t_bag *bag);
void	init_builtin(t_bag *bag);
bool	is_builtin(t_bag *bag, const char *cmd);
#endif
