# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 12:53:59 by gilee             #+#    #+#              #
#    Updated: 2021/12/04 21:28:17 by gilee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  				= minishell

CC 					= cc -g
CFLAGS 				= -Wall -Wextra -Werror

LIBFT_DIR 			= ./libft/
LIBFT_NAME			= libft.a
LIB					= $(LIBFT_DIR)$(LIBFT_NAME)
IREADLINE			= -I /opt/homebrew/opt/readline/include/
LREADLINE			= -L /opt/homebrew/opt/readline/lib/
SRCS				= ./main_02.c ./srcs/init/init_rl_catch_signals.c

OBJ					=	$(SRCS:.c=.o)

all : MAKE_LIB $(NAME)

.c.o:
	$(CC) $(CFLAGS) $(IREADLINE) -c -o $@ $<

$(NAME) : $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(LIB) $(LREADLINE) -lreadline -o $(NAME)

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

.PHONY : all clean fclean re
