#include "../../micro_shell.h"

static void	rd_input(char *str, int *fd_old)
{
	char	*buf;
	char	**split;
	int		fd;

	buf = ft_strdup(get_last_redirect(str, '<') + 1);
	split = ft_split(buf, ' ');
	fd = open(split[0], O_RDONLY);
	if (fd == -1)
		exit(ERROR);
	dup2(fd, *fd_old);
	*fd_old = fd;
	close(fd);
	close(*fd_old);
}

void	process_redirect_input(t_storage *bag, char *str)
{
	int	fd;
	/*
	if ((bag->redirect_input != 0 && bag->heredoc != 0))
		exit(SYNTAX_ERR);
	*/
	fd = 0;
	if (bag->redirect_input)
		rd_input(str, &fd);
	if (bag->heredoc)
		rd_heredoc(bag, str, &fd);
}
