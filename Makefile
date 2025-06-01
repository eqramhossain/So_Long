# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/01 16:52:58 by ehossain          #+#    #+#              #
#    Updated: 2025/06/01 16:53:02 by ehossain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCE = ./src/ft_all_character.c \
./src/ft_destroy_image.c \
./src/ft_error_exit.c \
./src/ft_exit_open.c \
./src/ft_free.c \
./src/ft_is_map_rectangular.c \
./src/ft_keypress.c \
./src/ft_main.c \
./src/ft_map_closed_left_right.c \
./src/ft_map_closed_top_bottom.c \
./src/ft_movements_left_right.c \
./src/ft_movements_up_down.c \
./src/ft_newline_check.c \
./src/ft_print_elements_to_window.c \
./src/ft_read_map.c \
./src/ft_redraw_map.c \
./src/ft_flood_fill_verif.c \
./src/ft_win.c \
./src/ft_xpm_to_image.c

OBJ = $(SOURCE:.c=.o)
INCLUDE = ./include
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
	@$(CC) $(CFLAGS) -I$(INCLUDE) -Iminilibx -O3 -c $< -o $@ 

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
	norminette src

.PHONY: clean fclean re all norm

# Define color variables
RED    = \033[0;31m
GREEN  = \033[0;32m
END     = \033[0m  # No Color (reset)
