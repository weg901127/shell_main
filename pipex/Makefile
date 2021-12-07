# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/16 11:21:01 by sehhong           #+#    #+#              #
#    Updated: 2021/10/06 15:16:28 by sehhong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS_M_DIR = ./srcs/mandatory/
SRCS_M = $(addprefix $(SRCS_M_DIR), \
			execve_with_path.c exit_macros.c fork_grandchildren.c \
			main.c parse_arguments.c print_errors.c redirect_fds.c \
			split_cmd.c wait_and_exit.c \
			)
OBJS_M = $(SRCS_M:.c=.o)

SRCS_B_DIR = ./srcs/bonus/
SRCS_B = $(addprefix $(SRCS_B_DIR), \
			execve_with_path_bonus.c exit_macros_bonus.c \
			fork_grandchildren_bonus.c get_next_line_bonus.c \
			heredoc_to_tmpfile_bonus.c main_bonus.c \
			parse_arguments_bonus.c parse_arguments2_bonus.c \
			print_errors_bonus.c redirect_fds_bonus.c \
			split_cmd_bonus.c wait_and_exit_bonus.c \
			)
OBJS_B = $(SRCS_B:.c=.o)

CC = gcc
RM = rm -f
AR = ar rcs
CFLAGS = -Wall -Werror -Wextra
INCLUDE = -I./includes

LIBFT_DIR = ./libft/
LIBFT_NAME = ft
LIBFT = $(LIBFT_DIR)libft.a

ifdef WITH_BONUS
	OBJS = $(OBJS_B)
else
	OBJS = $(OBJS_M)
endif

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -L$(LIBFT_DIR) -l$(LIBFT_NAME) -o $@ $^

$(LIBFT):
	make -C $(LIBFT_DIR) all

bonus:
	make WITH_BONUS=1 all 

clean:
	$(RM) $(OBJS_M) $(OBJS_B) 
	make -C $(LIBFT_DIR) clean 

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all 

.PHONY: all bonus clean fclean re
