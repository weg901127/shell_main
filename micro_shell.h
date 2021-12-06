/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_shell.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 19:46:02 by gilee             #+#    #+#             */
/*   Updated: 2021/12/06 15:57:59 by gilee            ###   ########.fr       */
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
# include "libft/libft.h"
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
#endif
