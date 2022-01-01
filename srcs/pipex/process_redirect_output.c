#include "../../micro_shell.h"

void	rd_output(char *str)
{
	char	*buf;
	char	**split;
	int		fd;	

	buf = ft_strdup(get_last_redirect(str, '>') + 1);
	split = ft_split(buf, ' ');
	fd = open(split[0], O_RDWR|O_CREAT|O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		exit(100);
	dup2(fd, 1);
	close(fd);
}

void	rd_append(char *str)
{
	char	*buf;
	char	**split;
	int		fd;	

	buf = ft_strdup(get_last_redirect(str, '>') + 1);
	split = ft_split(buf, ' ');
	fd = open(split[0], O_RDWR|O_CREAT|O_APPEND, S_IRUSR | S_IWUSR);
	if (fd == -1)
		exit(ERROR);
	dup2(fd, 1);
	close(fd);
}

void	process_redirect_output(t_storage *bag, char *str, int *pip)
{
	(void) pip;
	if ((bag->redirect_output != 0 && bag->append != 0)
			|| bag->redirect_output > 1 || bag->append > 1)
		exit(SYNTAX_ERR);
	else if (bag->redirect_output)
		rd_output(str);
	else if (bag->append)
		rd_append(str);
}
