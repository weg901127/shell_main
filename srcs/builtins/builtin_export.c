#include "../../micro_shell.h"

static  int    where_is_equal(char *str)
{
    int i;
    
    i = 0;
    while (str[i])
    {
        if (str[i] == '=')
            return (i);
        i++;
    }
    //'='가 없다.
    if (str[i] == '\0')
        return(-1);
}

void    builtin_export(t_storage *bag, char *arg)
{
    char    **arg_arr;
    int     i;
    int     equal_here;

    arg_arr = split_cmd(arg);
    equal_here = 0;
    i = 0;
    if (arg_arr[0] == NULL)
    {
        while (i < bag->environ->current_element_count)
        {
            ft_putstr_fd("declare -x ", STDOUT_FD);
            ft_putendl_fd(getALElement(bag->environ, i)->data, STDOUT_FD);
            i++;
        }
        set_environ(bag, EXIT_SUCCESS);
        return ;
    }
    // 다른 인자가 있을 때
    set_environ(bag, EXIT_SUCCESS);
    while (arg_arr[i])
    {
        equal_here = where_is_equal(arg_arr[i]);
        if (!equal_here)   //export =hihi 
        {
            set_environ(bag, EXIT_FAILURE);
            ft_print_error("export", arg_arr[i], "not a valid identifier");
        }
        else if (equal_here == -1)   //export water
        {
            update_env(bag->environ, arg_arr[i], get_value(bag->runtime_env, arg_arr[i]));
        }
        //export water=hihi
        i++;
    }
}

//water=haha로 쉘변수 업로드 가능 ->근데 이것도 구현하라는 말은 없지 않나?
//export water -> 등록되어 있던 쉘변수가 환경변수에 들어감.
//export water=haha -> 바로 환경변수로 저장.
//export water=haha asdf fdsa qwer

//export -> declare -x 환경변수list 보여줌 (done)
