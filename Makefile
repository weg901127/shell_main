# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 12:53:59 by gilee             #+#    #+#              #
#    Updated: 2021/12/15 11:58:03 by sehhong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  				= minishell
NAME_TEST			= test
CC 					= cc -g
CFLAGS 				= -Wall -Wextra -Werror

LIBFT_DIR 			= ./libft/
LIBFT_NAME			= libft.a
LIB					= $(LIBFT_DIR)$(LIBFT_NAME)
#IREADLINE			= -I /goinfre/sehhong/homebrew/opt/readline/include
#LREADLINE			= -L /goinfre/sehhong/homebrew/opt/readline/lib	
IREADLINE			= -I /opt/homebrew/opt/readline/include/
LREADLINE			= -L /opt/homebrew/opt/readline/lib/
#IREADLINE			= -I /Users/gilee/brew/opt/readline/include/
#LREADLINE			= -L /Users/gilee/brew/opt/readline/lib/
SRCS				= ./main.c					\
					  ./gnl/get_next_line.c				./gnl/get_next_line_utils.c \
					  ./srcs/array_list/arraylist.c 	./srcs/array_list/array_utils.c \
					  ./srcs/builtins/builtin_cd.c		./srcs/builtins/builtin_pwd.c \
					  ./srcs/builtins/builtin_echo.c 	./srcs/builtins/builtin_exit.c \
					  ./srcs/init/create_bag.c			./srcs/init/init_bag.c \
					  ./srcs/init/init_builtin.c		./srcs/init/init_rl_catch_signals.c \
					  ./srcs/init/init_environ.c 		./srcs/parse/getenviron.c\
					  ./srcs/parse/is_builtin.c			./srcs/pipex/pipex.c \
					  ./srcs/pipex/print_errors.c		./srcs/pipex/redirect_fds.c \
					  ./srcs/pipex/wait_and_exit.c		./srcs/pipex/parse_arguments.c \
					  ./srcs/pipex/execve_with_path.c	./srcs/pipex/split_cmd.c \
					  ./srcs/pipex/exit_macros.c		./srcs/pipex/parse_arguments2.c \
					  ./srcs/pipex/fork_grandchildren.c	./srcs/pipex/heredoc_to_tmpfile.c \
					  ./srcs/pipex/getpath.c			./srcs/pipex/my_which.c
OBJ					=	$(SRCS:.c=.o)
TEST				=	$(SRCS:main.c=test.c)
TEST_OBJ			=	$(TEST:.c=.o)

all : MAKE_LIB $(NAME)
.c.o:
	$(CC) $(CFLAGS) $(IREADLINE) -c -o $@ $<
$(NAME) : $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(LIB) $(LREADLINE) -lreadline -o $(NAME)
test : MAKE_LIB $(NAME_TEST)
.c.o:
	$(CC) $(CFLAGS) $(IREADLINE) -c -o $@ $<
$(NAME_TEST) : $(TEST_OBJ)
	$(CC) $(TEST_OBJ) $(CFLAGS) $(LIB) $(LREADLINE) -lreadline -o $(NAME_TEST)
clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
re : clean
	rm -f $(NAME)
	make -C . all
MAKE_LIB :
	make -C $(LIBFT_DIR) all
.PHONY : all test clean fclean re
