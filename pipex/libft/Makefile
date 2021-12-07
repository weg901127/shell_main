# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/08 17:15:30 by sehhong           #+#    #+#              #
#    Updated: 2021/10/06 16:32:26 by sehhong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
RM = rm -f
AR = ar rcs
CFLAGS = -Wall -Werror -Wextra
INCLUDE = -I.

FILES_M = ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove ft_memchr \
		 ft_memcmp ft_strlen ft_strlcpy ft_strlcat ft_strchr ft_strrchr \
		 ft_strnstr ft_strncmp ft_atoi ft_isalpha ft_isdigit ft_isalnum \
		 ft_isascii ft_isprint ft_toupper ft_tolower ft_calloc  ft_strdup \
		 ft_substr ft_strjoin ft_strtrim ft_split ft_itoa ft_strmapi \
		 ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd \
		 ft_malloc_fail_int ft_malloc_fail_str ft_ptr_free \
		 ft_strcopy_with_delimiter ft_strncpy ft_abs_int

FILES_B = ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back \
		 ft_lstdelone ft_lstclear ft_lstiter ft_lstmap

SRCS_M = $(addsuffix .c, $(FILES_M))
SRCS_B = $(addsuffix .c, $(FILES_B))

OBJS_M = $(addsuffix .o, $(FILES_M))
OBJS_B = $(addsuffix .o, $(FILES_B))

ifdef WITH_BONUS
	OBJS = $(OBJS_M) $(OBJS_B)
else
	OBJS = $(OBJS_M)
endif

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus:
	sleep 1
	make WITH_BONUS=1 all

clean:
	$(RM) $(OBJS_M) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re: fclean all 

.PHONY : all clean fclean re bonus
