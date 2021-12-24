#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
extern char **environ;

void	do_fork(pid_t *pid, char *str, int *pip, int cmd)
{
	*pid = fork();
	if (*pid == 0)
	{
		if (cmd != 0)
			dup2(pip[(cmd - 1) * 2], 0);
		if (cmd != 1)
			dup2(pip[cmd * 2 + 1], 1);
		for (int i = 2; i > -1 ; i--)
			close(pip[i]);
		if (cmd == 1)
		{
			char	*argv[] = {str,"a", NULL};
			execve(str, argv, environ);
		}
		char	*argv2[] = {str,NULL};
		execve(str, argv2, environ);
	}
}
int main(int argc, char **argv)
{
	pid_t pid;
	int		*pip;
	char	*arg[10];
	int		i;

	memset(arg, 0, sizeof(char *) * 10);
	arg[0] = "/bin/ls";
	arg[1] = "/usr/bin/grep";
	(void)argc;
	(void)argv;
	pip = (int *)malloc(sizeof(int) * 4);
	for (int i = 0; i < 2; i++)
		pipe(pip + 2*i);
	i = 0;
	while (arg[i])
	{
		do_fork(&pid, arg[i], pip, i);
		i++;
	}
	//printf("parent\n");
}
