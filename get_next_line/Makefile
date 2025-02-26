# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/18 11:31:42 by ehossain          #+#    #+#              #
#    Updated: 2025/02/26 14:32:40 by ehossain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc
CFLAGS= -Wall -Wextra -Werror
SOURCE= get_next_line.c get_next_line_utils.c 
NAME= get_next_line.a
OBJECT= ${SOURCE:.c=.o}


all: $(NAME)

$(NAME): $(OBJECT) 
	@ar rcs $(NAME) $(OBJECT) 
%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@
clean:
	@rm -f $(OBJECT)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
