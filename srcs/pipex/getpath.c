#include "../../micro_shell.h"

bool	getpath(t_storage *bag, char ***path_res)
{
	char	**tmp;
	char	**after_split;
	int		env_list_len;
	bool	res;

	res = false;
	tmp = get_environ(bag);
	env_list_len = bag->environ->current_element_count;
	while (--env_list_len >= 0)
	{
		after_split = ft_split(tmp[env_list_len], '=');
		//sehhong: 원래 strcmp(after_split[0], "PATH"))이였는데 제가 바꿨습니다. 혹시 몰라, 코멘트 남겨요.
		if (!ft_strncmp(after_split[0], "PATH", 4))
		{
			*path_res = ft_split(after_split[1], ':');
			res = true;
		}
	}
	return (res);
}
