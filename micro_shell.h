/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_shell.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 19:46:02 by gilee             #+#    #+#             */
/*   Updated: 2021/12/04 21:36:22 by gilee            ###   ########.fr       */
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

/* ./srcs/init */
void	init_rl_catch_signals();
#endif
