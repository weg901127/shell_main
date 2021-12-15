#include <stdio.h>
#include "libft/libft.h"
#include "srcs/array_list/arraylist.h"


//1안
char	*fndnchange(char *string, char target)
{
	int		cnt;
	char	*res;
	char	*tmp;

	res = (char *)ft_calloc(ft_strlen(string), sizeof(char));
	cnt = 0;
	while (*string)
	{
		if (*string == target && (cnt == 0 || *(string - 1) != '\\'))
		{
			string++;
			continue;
		}
		res[cnt] = *string;
		string++;
		cnt++;
	}
	tmp = ft_strdup(res);
	free(res);
	// \'파싱 로직 돌려야함..;;
	return (tmp);
}
//2안
char	*cutnjoin(char *string, char target)
{
	// ' 에서 다음 '까지 자른다 버퍼에 쪼인한다. 간단...
	// '가 있는지 없는지 확인
	// if (!ft_charcnt('\''))
	// 		없다면 종료
	// 있다면 로직 실행
	// 	1. '를 만나기 전까지 자른다. 하지만 이전 문자열이 \라면 '까지 자른다 (시작일때 끝일때 다르다_)
	// 	2. 복사 & 쪼인한다.
	// 	3. '를 만났다 --> 다음 '까지 자른다
	// 	4. 복사 & 쪼인한다.
	// 	5. 기존 string의 끝까지 이동했다면 종료
}
int	ft_splitcnt(char **src)
{
	int	cnt;

	cnt = 0;
	if (src == NULL || *src == NULL)
		return (0);
	while(src[cnt])
		cnt++;
	return (cnt);
}

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

int main()
{
	char	*str = "\'asdf\\\'\\\'";
	char	*buf;
	char	*buf2;
	char	**split;

	buf = ft_strdup(str);
	printf("%s\n", buf);
	buf2 = fndnchange(buf, '\'');
	printf("%s\n", buf2);
	split = ft_split(buf, '\'');
	while(*split)
	{
		printf("%s\n", *split++);
	}
	return 0;
}
