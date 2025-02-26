# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehossain <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/26 09:39:12 by ehossain          #+#    #+#              #
#    Updated: 2025/02/26 14:31:21 by ehossain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCE= ft_find_format.c ft_number_size.c ft_printf.c ft_putchar.c \
	ft_putdec.c ft_puthexa.c ft_putptr.c ft_putstr.c ft_putuns.c
NAME= libftprintf.a
CC= gcc
CFLAGS= -Wall -Wextra -Werror
OBJECTS= ${SOURCE:.c=.o}

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
