/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:56:51 by gilee             #+#    #+#             */
/*   Updated: 2022/01/10 10:56:52 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../micro_shell.h"

static void	handle_pipe_child(t_storage *bag, int *pip, int cmd, char *str)
{
	if (bag->redirect_input || bag->heredoc)
	{
		process_redirect_input(bag, str);
	}
	else
		dup2(bag->pipe_old, 0);
	if (bag->redirect_output || bag->append)
		process_redirect_output(bag, str);
	else
		if (cmd != bag->num_of_cmds - 1)
			dup2(pip[1], 1);
	close(pip[0]);
}

static void	handle_pipe_parent(t_storage *bag, int *pip, int cmd, pid_t pid)
{
	int	stat;

	waitpid(pid, &stat, 0);
	if (WEXITSTATUS(stat) == SYNTEX_ERR)
		ft_putstr_fd("SyntexError\n", 2);
	else if (WEXITSTATUS(stat) == ERROR)
		ft_putstr_fd("Error\n", 2);
	else if (WEXITSTATUS(stat) == 127)
		ft_putstr_fd("command not found\n", 2);
	else if (WIFSIGNALED(stat))
	{
		if (WTERMSIG(stat) == 3)
			ft_putstr_fd("Quit: 3", 1);
		ft_putstr_fd("\n", 1);
	}
	if (cmd == bag->num_of_cmds - 1)
		bag->last_exit_status = WEXITSTATUS(stat);
	close(pip[1]);
	bag->pipe_old = pip[0];
	bag->redirect_input = 0;
	bag->redirect_output = 0;
	bag->append = 0;
	bag->heredoc = 0;
	free(bag->location_input);
	free(bag->location_output);
}

static void	init_redirect_location(t_storage *bag)
{
	int	i;

	i = 0;
	while (i < MAXLEN)
	{
		*(bag->location_input + i) = -1;
		*(bag->location_output + i) = -1;
		i++;
	}
}

void	do_fork(t_storage *bag, char *str, int cmd)
{
	int		p[2];
	pid_t	pid;

	pipe(p);
	bag->location_input = (int *)ft_calloc(MAXLEN, sizeof(int));
	bag->location_output = (int *)ft_calloc(MAXLEN, sizeof(int));
	init_redirect_location(bag);
	has_redirect(bag, str);
	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	else if (pid == 0)
	{
		signal(SIGINT, handler_int_child);
		signal(SIGQUIT, SIG_DFL);
		handle_pipe_child(bag, p, cmd, str);
		my_execve(bag, str);
	}
	else
		handle_pipe_parent(bag, p, cmd, pid);
}
