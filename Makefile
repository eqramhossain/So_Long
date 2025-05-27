# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehossain <ehossainstudent.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/17 12:34:44 by ehossain          #+#    #+#              #
#    Updated: 2025/05/27 18:34:52 by ehossain         ###   ########.fr        #
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

re: fclean 
	@$(MAKE) re -C libft 
	@$(MAKE) all

norm:
	norminette libft 
	norminette sources

.PHONY: clean fclean re all norm

# Define color variables
RED    = \033[0;31m
GREEN  = \033[0;32m
END     = \033[0m  # No Color (reset)
