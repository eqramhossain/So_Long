# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/17 12:34:44 by ehossain          #+#    #+#              #
#    Updated: 2025/04/05 22:53:56 by ehossain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCE = $(shell find ./sources -name "*.c")
OBJ = $(SOURCE:.c=.o)
LIBFT_INCLUDE_PATH = ./libft/include
LIBFT = ./libft/libft.a
NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
MAKE = make --no-print-directory

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -Lminilibx -lmlx -lXext -lX11 -lm -lz -o $(NAME)
	@echo "$(GREEN)so_long complied$(END)"

%.o: %.c
	@$(CC) $(CFLAGS) -I$(LIBFT_INCLUDE_PATH) -Isources -Iminilibx -O3 -c $< -o $@ 

$(LIBFT):
	@$(MAKE) -C libft
	@echo "$(GREEN)libft complied$(END)"

clean: 
	@rm -f $(OBJ)
	@$(MAKE) clean -C libft
	@echo "$(RED)so_long and libft object file removed$(END)"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C libft
	@echo "$(RED)so_long and libft.a removed$(END)"

re: fclean all 
	@$(MAKE) re -C libft 

norm:
	norminette libft 
	norminette sources

.PHONY: clean fclean re all norm

# Define color variables
BLACK  = \033[0;30m
GRAY   = \033[0;37m
D_GRAY = \033[1;30m
RED    = \033[0;31m
L_RED  = \033[1;31m
GREEN  = \033[0;32m
L_GREEN= \033[1;32m
ORANGE = \033[0;33m
YELLOW = \033[1;33m
BLUE   = \033[0;34m
L_BLUE = \033[1;34m
PURPLE = \033[0;35m
L_PURPLE=\033[1;35m
CYAN   = \033[0;36m
L_CYAN = \033[1;36m
WHITE  = \033[1;37m
END     = \033[0m  # No Color (reset)
