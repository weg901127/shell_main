#include <unistd.h>
#include "../../micro_shell.h"

static void	rd_input(char *str, int *fd_old, int location)
{
	char	*buf;
	char	**split;
	int		fd;

	buf = str + location;
	split = ft_split(buf, ' ');
	fd = open(split[0], O_RDONLY);
	if (fd == -1)
		exit(ERROR);
	dup2(fd, *fd_old);
}

void	process_redirect_input(t_storage *bag, char *str)
{
	int	fd;
	int	i;

	fd = 0;
	i = 0;
	while (bag->location_input[i] != -1)
	{
		if ((bag->location_input[i]) - 2000 < 0)
			rd_input(str, &fd, bag->location_input[i] - 1000);
		else
			rd_heredoc(bag, str, &fd, bag->location_input[i] - 2000);
		i++;
	}
}
