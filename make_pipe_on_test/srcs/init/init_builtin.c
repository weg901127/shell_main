#include "../../micro_shell.h"

void	init_builtin(t_storage *bag)
{
	int				fd;
	char			*buf;
	t_ArrayListNode	element;
	int				ret;

	fd = open("./.builtin", O_RDONLY);
	while (1)
	{
		ret = get_next_line(fd, &buf);
		element.data = buf;
		if (*buf == 0)
		{	
			free(buf);
			buf = NULL;
			break ;
		}
		addALElement(bag->builtin, 0, element);
	}
	close(fd);
}
