#include "../../micro_shell.h"
#include <unistd.h>

void	heredoc_core(t_storage *bag, char *buf, int fd)
{
	char	*line;

	signal(SIGINT, handler_int_heredoc);
	while (true)
	{
		line = readline("> ");
		if (ft_strlen(line) && ft_strncmp(buf, line, ft_strlen(line)) == 0)
		{
			close(fd);
			break ;
		}
		if (line)
		{
			line = parse_env(bag, line, TRUE);
			write(fd, line, ft_strlen(line));
			write(fd, "\n", 1);
		}
		else
			break ;
	}
	exit(0);
}

static void	heredoc_rdline(t_storage *bag, char *buf, int fd, int *fd_old)
{
	int		pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(bag->named[0], *fd_old);
		heredoc_core(bag, buf, fd);
	}
	else
		wait(NULL);
}

void	rd_heredoc(t_storage *bag, char *str, int *fd_old, int location)
{
	char	*buf;
	int		fd;	

	if (*fd_old)
		close(*fd_old);
	buf = str + location;
	buf = ft_strtrim(buf, " ");
	if (buf && !(*buf))
		exit(SYNTEX_ERR);
	fd = open(".hd________", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	heredoc_rdline(bag, buf, fd, fd_old);
	signal(SIGINT, handler_int_child);
	signal(SIGQUIT, SIG_DFL);
	fd = open(".hd________", O_RDONLY);
	if (fd == -1)
		exit(1);
	dup2(fd, *fd_old);
	unlink(".hd________");
}
