# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/18 11:31:42 by ehossain          #+#    #+#              #
#    Updated: 2025/02/24 09:40:05 by ehossain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc
CFLAGS= -Wall -Wextra -Werror
SOURCE= get_next_line.c get_next_line_utils.c
OBJECT_LIBFT= ../libft/ft_calloc.o ../libft/ft_strlen.o ../libft/ft_strchr.o \
			  ../libft/ft_strjoin.o 
NAME= get_next_line.a
OBJECT= ${SOURCE:.c=.o}


all: $(NAME)

$(NAME): $(OBJECT) $(OBJECT_LIBFT)
	ar rcs $(NAME) $(OBJECT) $(OBJECT_LIBFT)

%.c: %.o
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECT)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
