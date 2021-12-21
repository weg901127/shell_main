#include "../../micro_shell.h"

static char	*cpy_environ(char *str)
{
	char	*ret;
	int		len_str;

	len_str = ft_strlen(str);
	if (str == NULL)
		return (NULL);
	ret = (char *)ft_calloc(len_str + 1, sizeof(char));
	ft_memcpy(ret, str, len_str);
	return (ret);
}

void	init_environ(t_storage *bag)
{
	extern char		**environ;
	t_ArrayListNode	element;
	int				i;

	i = 0;
	while (environ[i])
	{
		//bash 처음 시작할때, 환경변수 OLDPWD 존재 안함.
		if (!strncmp_exact(environ[i], "OLDPWD", '=') && !strncmp_exact(environ[i], "_", '='))
		{
			element.data = cpy_environ(environ[i]);
			addALElement(bag->environ, bag->environ->current_element_count, element);
		}
		i++;
	}
}



	// //bash 처음 시작하자마자, echo $_하면 /bin/bash로 뜸.
	// //아래처럼 하면, "micronshell의 위치/microshell"이 환경변수 "_"에 저장되서 시작됨.
	// tmp = ft_strjoin(get_value(bag->environ, "PWD"), "/microshell");
	// getALElement(bag->environ, bag->environ->current_element_count - 1)->data = \
	// 	ft_strjoin("_=", tmp);
	// free(tmp);
	// tmp = NULL;