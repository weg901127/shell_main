#include "../../micro_shell.h"

static void	rd_input(char *str)
{
	char	*buf;
	char	**split;
	int		fd;	

	buf = ft_strdup(get_last_redirect(str, '<') + 1);
	split = ft_split(buf, ' ');
	fd = open(split[0], O_RDONLY);
	if (fd == -1)
		exit(ERROR);
	dup2(fd, 0);
	close(fd);
}

void	process_redirect_input(t_storage *bag, char *str)
{
	if ((bag->redirect_input != 0 && bag->heredoc != 0)
			|| bag->redirect_input > 1 || bag->heredoc > 1)
		exit(SYNTAX_ERR);
	else if (bag->redirect_input)
		rd_input(str);
	else if (bag->heredoc)
		rd_heredoc(bag, str);
}
