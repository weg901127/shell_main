#include "libft/libft.h"
#include "micro_shell.h"
#include "srcs/array_list/arraylist.h"
#include <assert.h>
#include <sys/_types/_pid_t.h>
#include <unistd.h>
/*
int	ft_charcnt(char *src, char target)
{
	int	cnt;

	cnt = 0;
	if (src == NULL || *src == 0)
		return (0);
	while (*src)
	{
		if (*src == target)
			cnt++;
		src++;
	}
	return (cnt);
}
*/
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
		if (ft_isspace(*tmp) || *tmp == '\'' || *tmp =='\"')
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
	int		*zone;

	tmp = string;
	ft_memset(buf, 0, 10000);
	ft_memset(var_buf, 0, 1000);
	zone = get_zone(string);
	while (1)
	{
		ft_memccpy(buf, tmp, '$', ft_strlen(tmp));
		tmp = ft_strchr(tmp, '$') + 1;
		if (buf[ft_strlen(buf) - 1] == '$' && zone[ft_strlen(buf) - 1] == 1)
		{
			buf[ft_strlen(buf) - 1] = '\0';
			ft_memcpy(var_buf, tmp, get_env_len(tmp));
			tmp = tmp + get_env_len(tmp);
			ft_strlcat(buf, get_value(bag->environ, var_buf), 10000);
		}
		if (!*tmp)
			break;
	}
	free(zone);
	printf("%s", buf);
	return NULL;
}

int main(int argc, char **argv)
{
	t_storage	*bag;

	bag = create_bag();
	init_bag(bag);
	init_builtin(bag);
	init_environ(bag);
	(void)argc;
	printf("%s\n", argv[1]);
	parse_env(bag, argv[1]);
	return 0;
}
/*
// extern char **environ;
// int main(int argc, char **argv)
// {
// 	t_storage	*bag;
// 	int			i;
// 	//char		*arr[3] = {
// 	//	"ls",
// 	//};
// 	//pid_t		pid;

// 	i = 0;
// 	(void)argc;
// 	(void)argv;
// 	bag = create_bag();
// 	init_bag(bag);
// 	assert(bag != 0);

	
// 	init_builtin(bag);
// 	assert(bag->builtin != 0);

// 	assert(is_builtin(bag, "echo") == 1);
// 	assert(is_builtin(bag, "cd") == 1);
// 	assert(is_builtin(bag, "pwd") == 1);
// 	assert(is_builtin(bag, "export") == 1);
// 	assert(is_builtin(bag, "unset") == 1);
// 	assert(is_builtin(bag, "env") == 1);
// 	assert(is_builtin(bag, "exit") == 1);
		
// 	init_environ(bag);
// 	i = 0;
// 	while (i < bag->environ->currentElementCount)
// 	{
// 		printf("%s\n",  getALElement(bag->environ, i)->data);
// 		i++;
// 	}
	

// 	printf("\033[32;1mDONE\n\033[m");
// }

void	print_all_env(t_storage *bag)
{
	int	i;

	i = 0;
	while (i < bag->environ->current_element_count)
	{
		printf("%s\n", getALElement(bag->environ, i)->data);
		i++;
	}
}

extern char **environ;
int	main(void)
{
	t_storage	*bag;
	bag = create_bag();
	init_bag(bag);
	init_builtin(bag);
	init_environ(bag);
	printf("%s",get_value(bag->environ, "PATH"));
	printf("\033[32;1mDONE\n\033[m");
}
*/
