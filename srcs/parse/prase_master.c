#include "../../micro_shell.h"
//TODO tab 말고 다른애들도 split할때 처리하기
char	*cutnjoin(char *string, char target)
{
	char	*flag[2];
	char	buf[10000];

	flag[START] = string;
	flag[END] = string;
	ft_memset(buf, 0, 10000);
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
	//변수 이름에대해서 예외상황이 많다.. 다 처리해줘야함
	//숫자먼저 오는경우 (한자리까지 받는다)
	//알파벳이 먼저오면 숫자 아무리많이와도 상관없다.
	//특수문자도 마찬가지
	//--> 1글자 먼저 해석하는경우
	//숫자하나올때
	//특수문자하나올때
	//뒤에 뭐가오든 기존에 예약된게있다면 그 결과에 추가로 뒤에오는애들을 붙인다.
	int	res;

	res = 0;
	while (*tmp)
	{
		if (ft_isspace(*tmp) || *tmp == '\'' || *tmp =='\"' || *tmp == '$')
			break;
		res++;
		tmp++;
	}
	return (res);
}

char	*parse_env(t_storage *bag, char *string)
{
	char	buf[10000];
	char	var_buf[1000];
	char	*tmp;
	int		buflen;
	int		*zone;

	if (!ft_strchr(string, '$'))
		return (ft_strdup(string));
	tmp = string;
	ft_memset(buf, 0, 10000);
	ft_memset(var_buf, 0, 1000);
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
				ft_strlcat(buf, get_value(bag->environ, var_buf), 10000);
		}
		if (!tmp)
			break;
	}
	free(zone);
	return ft_strdup(buf);
}
void	execve_builtin(t_storage *bag, char *arg)
{
	char	buf1[10000];
	char	buf2[10000];

	ft_memset(buf1, 0, 10000);
	ft_memset(buf2, 0, 10000);
	ft_memccpy(buf1, arg, ' ', ft_strlen(arg));
	if (buf1[ft_strlen(buf1) - 1] == ' ')
		buf1[ft_strlen(buf1) - 1] = '\0';
	if (ft_strlen(buf1))
		ft_memcpy(buf2, ft_strchr(arg, ' ') + 1, ft_strlen(ft_strchr(arg, ' ')));
	if (!ft_strncmp(buf1, "cd", 2))
		builtin_cd(bag, buf2);
	else if (!ft_strncmp(buf1, "echo", 4))
		builtin_echo(bag, buf2, 0);
	else if (!ft_strncmp(buf1, "pwd", 3))
		builtin_pwd(bag);
	else if (!ft_strncmp(buf1, "exit", 4))
		builtin_exit(bag, buf2);
	else if (!ft_strncmp(buf1, "export", 6))
		builtin_export(bag, buf2);
	else if (!ft_strncmp(buf1, "env", 3))
		builtin_env(bag);
	else if (!ft_strncmp(buf1, "unset", 5))
		builtin_unset(bag, buf2);
}
void	execve_cmd(t_storage *bag, char	*arg)
{
	char	buf[10000];

	ft_memset(buf, 0, 10000);
	ft_memccpy(buf, arg, ' ', ft_strlen(arg));
	if (buf[ft_strlen(buf) - 1] == ' ')
		buf[ft_strlen(buf) - 1] = '\0';
	if(is_builtin(bag, buf))
		execve_builtin(bag, arg);
}
bool parse_master(t_storage *bag)
{
	bool	res;
	char	*buf;
	char	*buf2;
	char	*buf3;

	res = false;
	buf = parse_env(bag, bag->input);
	buf2 = cutnjoin(buf, '\'');
	buf3 = cutnjoin(buf2, '\"');
	free(buf);
	free(buf2);
	//free(buf3);
	execve_cmd(bag, buf3);
	return (res);
}
