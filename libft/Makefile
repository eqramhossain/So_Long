# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/23 14:36:30 by ehossain          #+#    #+#              #
#    Updated: 2025/03/23 16:04:45 by ehossain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ_DIR = obj
SOURCE = ${shell find ./src -name "*.c"} 
NAME = libft.a
OBJECT = ${SOURCE:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJECT)
	@mkdir -p obj
	@ar rcs $(NAME) $(OBJECT)
	@echo "libft complied"
	@echo mv -f $(OBJECT) -t $(OBJ_DIR)

%.o:%.c
	@$(CC) $(CFLAGS) -Iinclude -c $< -o $@

clean : 
	@rm -rf $(OBJ_DIR)
	@echo "libft object file removed"

fclean : clean
	@rm -f $(NAME)
	@echo "libft.a removed"

re : fclean all

.PHONY: clean fclean re all
