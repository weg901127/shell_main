# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 01:21:24 by gilee             #+#    #+#              #
#    Updated: 2021/11/24 01:21:56 by gilee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      = gcc
LIB		= ar rcs
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -f
NAME	= libft.a
INC     = ./libft.h

MEM		= ft_memchr.c ft_memcmp.c \
		  ft_memcpy.c ft_memset.c \
		  ft_memccpy.c ft_memmove.c \
		  ft_bzero.c ft_calloc.c

STR		= ft_strchr.c ft_strdup.c \
		  ft_strlen.c ft_strjoin.c \
		  ft_strlcat.c ft_strlcpy.c \
		  ft_strmapi.c ft_strncmp.c \
		  ft_strnstr.c ft_strrchr.c \
		  ft_strtrim.c ft_split.c \
		  ft_itoa.c ft_atoi.c \
		  ft_tolower.c ft_toupper.c \
		  ft_substr.c

IS		= ft_isalnum.c ft_isalpha.c \
		  ft_isascii.c ft_isdigit.c \
		  ft_isprint.c ft_isspace.c

FD		= ft_putnbr_fd.c ft_putstr_fd.c \
		  ft_putchar_fd.c ft_putendl_fd.c

LST		= ft_lstmap.c ft_lstnew.c \
		  ft_lstiter.c ft_lstlast.c \
		  ft_lstclear.c ft_lstsize.c \
		  ft_lstdelone.c ft_lstadd_back.c \
		  ft_lstadd_front.c

OBJ_MEM	= $(MEM:.c=.o)
OBJ_STR	= $(STR:.c=.o)
OBJ_IS	= $(IS:.c=.o)
OBJ_FD	= $(FD:.c=.o)
OBJ_LST	= $(LST:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -I$(INC)

$(NAME) : $(OBJ_MEM) $(OBJ_STR) $(OBJ_IS) $(OBJ_FD)
	$(LIB) $@ $^

all : $(NAME)

bonus : $(OBJ_LST)
	$(LIB) $(NAME) $^

clean :
	$(RM) $(OBJ_MEM) $(OBJ_STR) $(OBJ_IS) $(OBJ_FD) $(OBJ_LST)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
