#include "../../micro_shell.h"

void	rd_output(char *str, int location)
{
	char	*buf;
	char	**split;
	int		fd;	

	buf = str + location;
	split = ft_split(buf, ' ');
	fd = open(split[0], O_RDWR|O_CREAT|O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		exit(100);
	dup2(fd, 1);
	close(fd);
}

void	rd_append(char *str, int location)
{
	char	*buf;
	char	**split;
	int		fd;	

	buf = str + location;
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
	int	i;

	i = 0;
	while (bag->location_output[i] != -1)
	{
		if ((bag->location_output[i]) - 2000 < 0)
			rd_output(str, (bag->location_output[i]) - 1000);
		else
			rd_append(str, (bag->location_output[i]) - 2000);
		i++;
	}
}
