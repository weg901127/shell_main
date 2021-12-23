#include "../../micro_shell.h"

//TODO trim해주기
char	*cutnjoin(char *string, char target)
{
	char	*flag[2];
	char	buf[MAXLEN];

	if (ft_charcnt(string, target) & 1)
	{
		ft_print_error("syntax error", NULL, NULL);
		exit(EXIT_FAILURE);
	}
	flag[START] = string;
	flag[END] = string;
	ft_memset(buf, 0, MAXLEN);
	int	tmp = 0;
	while (1)
	{
		tmp = ft_strlen(buf);
		ft_memccpy(buf + tmp, flag[START], target, ft_strlen(flag[START]));
		if (ft_strchr(flag[START], target))
			flag[START] = flag[START] + (ft_strchr(flag[START], target) - flag[START] + 1);
		else
			break;
		if (buf[ft_strlen(buf) - 1] == target)
		{
			if (ft_strlen(buf) && buf[ft_strlen(buf) - 2] == '\\')
				buf[ft_strlen(buf) - 2] = target;
			buf[ft_strlen(buf) - 1] = '\0';
		}
	}
	return ft_strdup(buf);
}



int	*get_zone(char	*string)
{
	int	*buf;
	int	start;
	int	i;

	i = 0;
	start = 0;
	buf = (int *)ft_calloc(ft_strlen(string), sizeof(int));
	while (*string)
	{
		if (*string == '\'')
		{
			buf[i] = 2;
			if (ft_strchr(string + 1, '\''))
				start = !start;
			else if (!ft_strchr(string + 1, '\''))
				start = 0;
		}
		else if (start)
			buf[i] = 0;
		else
			buf[i] = 1;
		string++;
		i++;
	}
	return (buf);
}

int	get_env_len(char *tmp)
{
	int	res;

	res = 0;
	while (*tmp)
	{
		if (ft_isspace(*tmp) || *tmp == '\'' || *tmp =='\"' || *tmp == '$' || *tmp == '|')
			break;
		res++;
		tmp++;
	}
	return (res);
}

char	*parse_env(t_storage *bag, char *string)
{
	char	buf[MAXLEN];
	char	var_buf[MAX_ENVLEN];
	char	*tmp;
	int		buflen;
	int		*zone;

	if (!ft_strchr(string, '$'))
		return (ft_strdup(string));
	tmp = string;
	ft_memset(buf, 0, MAXLEN);
	ft_memset(var_buf, 0, MAX_ENVLEN);
	zone = get_zone(string);
	while (1)
	{
		buflen = ft_strlen(buf);
		ft_memccpy(buf + buflen, tmp, '$', ft_strlen(tmp));
		tmp = ft_strchr(tmp, '$');
		if (tmp)
			tmp += 1;
		if (buf[ft_strlen(buf) - 1] == '$' && zone[ft_strlen(string) - ft_strlen(tmp) - 1] == 1)
		{
			buf[ft_strlen(buf) - 1] = '\0';
			ft_memcpy(var_buf, tmp, get_env_len(tmp));
			tmp = tmp + get_env_len(tmp);
			//TODO get_value NULL처리
			if (get_value(bag->environ, var_buf))
				ft_strlcat(buf, get_value(bag->environ, var_buf), MAXLEN);
		}
		if (!tmp)
			break;
	}
	free(zone);
	return ft_strdup(buf);
}

bool parse_master(t_storage *bag)
{
	char	*buf;
	char	**args;
	int		i;
	pid_t	pid;
	int		status;

	i = 0;
	buf = parse_env(bag, bag->input);
	args = ft_split(buf, '|');
	free(buf);
	//args에 저장 잘 되어 있음.

	allocate_before_fork(bag, args);
	pid = fork();
	print_error_and_exit("fork() has failed", NULL, pid);
	if (pid == 0)
	{
		while (args[i])
		{
			buf = ft_strtrim(args[i], " ");
			ft_putchar_fd('\n', 2);
			ft_putendl_fd(buf, 2);
			//args[i]의 head & tail의 스페이스가 지워져서 프린트 잘됨.

			//두번째 포크 -> 두번째 손자 생성
			//fork_grandchild(bag, buf, i);
			if (i != bag->num_of_cmds - 1)
				print_error_and_exit("pipe() has failed", NULL, pipe(bag->pipe_fds[i]));
			bag->grandchild_pids[i] = fork();
			print_error_and_exit("fork() has failed", NULL, bag->grandchild_pids[i]);
			if (bag->grandchild_pids[i] == 0)
			{
				if (i != 0)
					close(bag->pipe_fds[i - 1][PIPE_WR_FD]);
				if (i != bag->num_of_cmds - 1)
					close(bag->pipe_fds[i][PIPE_RD_FD]);
				redirect_fds(bag, i);
				execve_cmd(bag, args[i]);
				// ft_putendl_fd(ft_itoa(i), 2);
				// exit(i);
			}
			if (i != 0)
			{	
				close(bag->pipe_fds[i - 1][PIPE_RD_FD]);
				close(bag->pipe_fds[i - 1][PIPE_WR_FD]);
			}
			
			i++;
			free(buf);
		}
		wait_and_exit_for_grandchildren(bag);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (wifexited(status))
		{	
			ft_putstr_fd("success to wait my child: ", 2);
			ft_putendl_fd(ft_itoa(wexitstatus(status)), 2);
		}
		else
			ft_putstr_fd("failed to wait my child", 2);
		exit_for_child(status);
	}

	
	//pipex(bag, args);

	while (i--)
		free(args[i]);
	free(args);
	return (false);
}
