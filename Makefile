# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/17 12:34:44 by ehossain          #+#    #+#              #
#    Updated: 2025/03/09 12:13:45 by ehossain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCE = $(shell find ./sources -name "*.c")
OBJ = $(SOURCE:.c=.o)
LIBFT = ./libft/libft.a
NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
MAKE = make --no-print-directory
# TEST= $(shell find so_long)

all: $(NAME)

# @if [ "$(TEST)" = "$(NAME)" ]; then \
# 	echo "hello world"; \
# fi


# -------------------------- FOR LINUX ------------------------------
#
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -Lminilibx -lmlx -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Ilibft -Isources -Iminilibx -O3 -c $< -o $@ 
#
# -------------------------- FOR LINUX ------------------------------

# -------------------------- FOR MACOS ------------------------------
#
# $(NAME): $(OBJ) $(LIBFT)
# 	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -Lminilibx_mac -lmlx -framework OpenGL -framework AppKit -o $(NAME)
#
# %.o: %.c
# 	@$(CC) $(CFLAGS) -Ilibft -Isources -Iminilibx_mac -c $< -o $@
#
# -------------------------- FOR MACOS ------------------------------

$(LIBFT):
	@$(MAKE) -C libft

clean: 
	@rm -f $(OBJ)
	@$(MAKE) clean -C libft

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C libft 

re: fclean all 
	@$(MAKE) re -C libft 
	@$(MAKE) all 

norm:
	norminette libft 
	norminette sources

leack:
	valgrind ./so_long ./valid_maps/small_map.ber

funcheck:
	funcheck ./so_long ./valid_maps/small_map.ber

.PHONY: clean fclean re all norm leack funcheck

# Black='\e[0;30m'
# Gray='\e[0;37m'
# D_Gray='\e[1;30m'
# Red='\e[0;31m'
# L_Red='\e[1;31m'
# Green='\e[0;32m'
# L_Green='\e[1;32m'
# Orange='\e[0;33m'
# Yellow='\e[1;33m'
# Blue='\e[0;34m'
# L_Blue='\e[1;34m'
# Purple='\e[0;35m'
# L_Purple='\e[1;35m'
# Cyan='\e[0;36m'
# L_Cyan='\e[1;36m'
# White='\e[1;37m'
# NC='\e[0m'
