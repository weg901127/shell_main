# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gilee <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 20:36:37 by gilee             #+#    #+#              #
#    Updated: 2022/01/10 20:39:38 by gilee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  				= minishell
NAME_TEST			= test
CC 					= cc
CFLAGS 				= -Wall -Wextra -Werror

LIBFT_DIR 			= ./libft/
LIBFT_NAME			= libft.a
LIB					= $(LIBFT_DIR)$(LIBFT_NAME)
#IREADLINE			= -I /opt/homebrew/opt/readline/include/
#LREADLINE			= -L /opt/homebrew/opt/readline/lib/
IREADLINE			= -I /Users/gilee/brew/opt/readline/include/
LREADLINE			= -L /Users/gilee/brew/opt/readline/lib/
SRCS				= ./main.c					\
					  ./gnl/get_next_line.c				./gnl/get_next_line_utils.c \
					  ./srcs/array_list/arraylist.c 	./srcs/array_list/array_utils.c \
					  ./srcs/builtins/builtin_cd.c		./srcs/builtins/builtin_pwd.c \
					  ./srcs/builtins/builtin_echo.c 	./srcs/builtins/builtin_exit.c \
					  ./srcs/builtins/builtin_env.c		./srcs/builtins/get_value.c \
					  ./srcs/builtins/builtin_unset.c	./srcs/builtins/set_environ.c \
					  ./srcs/builtins/update_env.c 		./srcs/builtins/strncmp_exact.c \
					  ./srcs/builtins/count_str_array.c ./srcs/builtins/builtin_export.c \
					  ./srcs/init/create_bag.c			./srcs/init/init_bag.c \
					  ./srcs/init/init_builtin.c		./srcs/init/init_rl_catch_signals.c \
					  ./srcs/init/init_environ.c 		./srcs/parse/get_environ.c \
					  ./srcs/init/init_runtime_env.c 	./srcs/parse/prase_master.c \
					  ./srcs/parse/is_builtin.c			./srcs/parse/parse_space.c \
					  ./srcs/parse/split_pipe.c			./srcs/parse/split_echo.c \
					  ./srcs/parse/cutnjoin.c			./srcs/parse/get_zone.c \
					  ./srcs/parse/get_env_len.c 		./srcs/parse/parse_env.c \
					  ./srcs/pipex/pipex.c 				./srcs/pipex/handlers.c \
					  ./srcs/pipex/execve_builtin.c 	./srcs/pipex/my_execve.c \
					  ./srcs/pipex/getpath.c			./srcs/pipex/my_which.c \
					  ./srcs/pipex/my_heredoc.c			./srcs/pipex/has_redirect.c \
					  ./srcs/pipex/get_last_redirect.c	./srcs/pipex/process_redirect_input.c \
					  ./srcs/pipex/do_not_fork.c		./srcs/pipex/process_redirect_output.c \
					  ./srcs/pipex/do_fork.c			./srcs/pipex/has_rd_for_rm.c
OBJ					=	$(SRCS:.c=.o)
TEST				=	$(SRCS:main.c=test.c)
TEST_OBJ			=	$(TEST:.c=.o)

all : MAKE_LIB $(NAME)
.c.o:
	$(CC) $(CFLAGS) $(IREADLINE) -c -o $@ $<
$(NAME) : $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(LIB) $(LREADLINE) -lreadline -o $(NAME)
clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)
	rm -f $(NAME_TEST)
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) fclean
re : clean
	rm -f $(NAME)
	make -C . all
MAKE_LIB :
	make -C $(LIBFT_DIR) all
.PHONY : all clean fclean re
