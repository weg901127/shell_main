/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:57:42 by gilee             #+#    #+#             */
/*   Updated: 2022/01/10 10:57:42 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

static void	do_child(t_storage *bag, char **args, int *i)
{
	while (args[++(*i)])
		do_fork(bag, args[*i], *i);
	exit(bag->last_exit_status);
}

static void	do_parent(t_storage *bag, int pid)
{
	int	status;

	waitpid(pid, &status, 0);
	bag->last_exit_status = WEXITSTATUS(status);
	set_environ(bag, bag->last_exit_status);
	if (WEXITSTATUS(status) == SYNTEX_ERR)
		ft_putstr_fd("SyntexError\n", 2);
}

void	pipex(t_storage *bag, char **args)
{
	int		i;
	pid_t	pid;
	int		exit_status;

	i = -1;
	exit_status = EXIT_SUCCESS;
	bag->pipe_old = 0;
	bag->num_of_cmds = ft_splitcnt(args);
	if (do_not_fork(bag, args[0]))
	{
		exit_status = execve_builtin(bag, args[0]);
		set_environ(bag, exit_status);
		return ;
	}
	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == 0)
		do_child(bag, args, &i);
	else
		do_parent(bag, pid);
	signal(SIGINT, handler_int);
}
