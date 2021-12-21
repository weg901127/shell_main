#include "../micro_shell.h"

/*
//cd
int	main(void)
{
	t_storage	*bag;
	bag = create_bag();
	init_bag(bag);
	init_builtin(bag);
	init_environ(bag);
	init_runtime_env(bag);


//cd
    //valid path
   	//builtin_cd(bag, "srcs");
    
	//invalid path
	//builtin_cd(bag, "alksdjflkajsdlfk");

	//여러개 일때 1
	//builtin_cd(bag, "aasjdflkj srcs galksjdfljas");

	//여러개 일떄 2
	// builtin_cd(bag, "srcs gnl libft");

	//여러개 일때 3
	builtin_cd(bag, "srcs a b c d ");
    printf("$?=%s\n", get_value(bag->runtime_env, "?"));
	builtin_pwd(bag);
    printf("$?=%s\n", get_value(bag->runtime_env, "?"));


//pwd
    builtin_pwd(bag);
    printf("$?=%s\n", get_value(bag->runtime_env, "?"));
	builtin_pwd(bag);
	builtin_cd(bag, "gnl");
    printf("$?=%s\n", get_value(bag->runtime_env, "?"));
	builtin_pwd(bag);	
    printf("$?=%s\n", get_value(bag->runtime_env, "?"));


//echo
	builtin_echo(bag, "-n alsdk.fjla//ks'jdlfk'jp                rweporiwpe qwperpowier /flkasjdf. ");	
    printf("$?=%s\n", get_value(bag->runtime_env, "?"));
	builtin_echo(bag, "-nalsdk.fjla//ks'jdlfk'j      sfjdlkjfslkjfalksd       irweporiwpe qwperpowier /flkasjdf. ");
    printf("$?=%s\n", get_value(bag->runtime_env, "?"));


//env
	builtin_env(bag);
	printf("---------------------------------------\n");
    printf("$?=%s\n", get_value(bag->runtime_env, "?"));
	builtin_env(bag);
	printf("---------------------------------------\n");
    printf("$?=%s\n", get_value(bag->runtime_env, "?"));


//exit
	//echo $? 해보면 1
    builtin_cd(bag, "alksjdflkajs ajlksdjflk ");
	//builtin_exit(bag, "");

	//echo $? > 89 (345 % 256)
	//builtin_exit(bag, "345");

	//error : too many arguments -> echo $? = 1 & exit안함.
	//builtin_exit(bag, "7 8 9 10");
	//printf("$?=%s\n", get_value(bag->runtime_env, "?"));
	
    //error : too many arguments -> echo $? = 1 & exit안함.
	//builtin_exit(bag, "81 t 20");
	//printf("$?=%s\n", get_value(bag->runtime_env, "?"));

	//error: numeric argument required -> echo $? = 255 & exit함!
	builtin_exit(bag, "a 1 4");
	printf("$?=%s\n", get_value(bag->runtime_env, "?"));
	printf("\033[32;1mDONE\n\033[m");


//export
    //bash-3.2$ water=huhu (쉘변수에 추가하는 역할)
	element.data = "water=huhu";
	addALElement(bag->runtime_env, bag->runtime_env->current_element_count, element);
	printf("water = %s\n", get_value(bag->runtime_env, "water"));

	builtin_export(bag, "asdf=hihi fdsa=haha qwer rewq");
	printf("$?=%s\n", get_value(bag->runtime_env, "?"));
	builtin_env(bag);
	builtin_export(bag, "=hihih asdf=yum_yum water");
	printf("%s\n", get_value(bag->runtime_env, "?"));
	builtin_env(bag);
	printf("\033[32;1mDONE\n\033[m");

//unset
    //bash-3.2$ water=huhu (쉘변수에 추가하는 역할)
	element.data = "water=huhu";
	addALElement(bag->runtime_env, bag->runtime_env->current_element_count, element);
	printf("water = %s\n", get_value(bag->runtime_env, "water"));

	builtin_export(bag, "asdf=hihi fdsa=haha qwer rewq");
	builtin_export(bag, "=hihih asdf=yum_yum water");
	builtin_unset(bag, "asdf");
	builtin_env(bag);
	builtin_unset(bag, "water");
	builtin_env(bag);
	printf("\033[32;1mDONE\n\033[m");
}
*/
