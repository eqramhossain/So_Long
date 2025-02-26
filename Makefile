# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/17 12:34:44 by ehossain          #+#    #+#              #
#    Updated: 2025/02/26 19:23:55 by ehossain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCE = $(shell find ./so_long_mandatory -name "*.c")
OBJ = $(SOURCE:.c=.o)
LIB_LIBFT= ./libft/libft.a
LIB_FT_PRINTF= ./ft_printf/libftprintf.a
LIB_GET_NEXT_LINE= ./get_next_line/get_next_line.a
LIB_COMBINE = $(LIB_LIBFT) $(LIB_FT_PRINTF) $(LIB_GET_NEXT_LINE)
NAME= so_long
CC= gcc
CFLAGS= -Wall -Wextra -Werror
MAKE = make --no-print-directory
# TEST= $(shell find so_long)

all: $(NAME)


# @if [ "$(TEST)" = "$(NAME)" ]; then \
# 	echo "hello world"; \
# fi


# -------------------------- FOR LINUX ------------------------------

$(NAME): $(OBJ) $(LIB_LIBFT) $(LIB_FT_PRINTF) $(LIB_GET_NEXT_LINE)
	@$(CC) $(CFLAGS) $(OBJ) $(LIB_COMBINE) -Lminilibx \
		-lmlx -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -Ilibft -Iso_long_mandatory -Ift_printf \
		-Iget_next_line -Iminilibx -O3 -c $< -o $@ 

# -------------------------- FOR LINUX ------------------------------

# -------------------------- FOR MACOS ------------------------------
#
# $(NAME): $(OBJ) $(LIB_LIBFT) $(LIB_FT_PRINTF) $(LIB_GET_NEXT_LINE)
# 	$(CC) $(CFLAGS) $(OBJ) $(LIB_COMBINE) -Lminilibx_mac -lmlx -framework OpenGL -framework AppKit \
# 	-o $(NAME)
#
# %.o: %.c
# 	$(CC) $(CFLAGS) -Iminilibx_mac -c $< -o $@
#
# -------------------------- FOR MACOS ------------------------------

$(LIB_LIBFT):
	@$(MAKE) -C libft

$(LIB_FT_PRINTF):
	@$(MAKE) -C ft_printf

$(LIB_GET_NEXT_LINE):
	@$(MAKE) -C get_next_line 

clean: 
	@rm -f $(OBJ)
	@$(MAKE) clean -C libft
	@$(MAKE) clean -C ft_printf 
	@$(MAKE) clean -C get_next_line 
	@echo "so_long cleaned"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C libft 
	@$(MAKE) fclean -C ft_printf 
	@$(MAKE) fclean -C get_next_line
	@echo "so_long fcleaned"

re: fclean 
	@$(MAKE) re -C libft 
	@$(MAKE) re -C ft_printf 
	@$(MAKE) re -C get_next_line
	@$(MAKE) all 
	@echo "so_long recomplied"

norm:
	norminette libft 
	norminette ft_printf
	norminette get_next_line
	norminette so_long_mandatory

leack:
	valgrind ./so_long ./so_long_maps/small_map.ber

funcheck:
	funcheck ./so_long ./so_long_maps/small_map.ber

.PHONY: clean fclean re all norm leack funcheck

Black='\e[0;30m'
Gray='\e[0;37m'
D_Gray='\e[1;30m'
Red='\e[0;31m'
L_Red='\e[1;31m'
Green='\e[0;32m'
L_Green='\e[1;32m'
Orange='\e[0;33m'
Yellow='\e[1;33m'
Blue='\e[0;34m'
L_Blue='\e[1;34m'
Purple='\e[0;35m'
L_Purple='\e[1;35m'
Cyan='\e[0;36m'
L_Cyan='\e[1;36m'
White='\e[1;37m'
NC='\e[0m'
