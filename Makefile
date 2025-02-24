# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/17 12:34:44 by ehossain          #+#    #+#              #
#    Updated: 2025/02/24 09:46:23 by ehossain         ###   ########.fr        #
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

all: $(NAME)

# -------------------------- FOR LINUX ------------------------------

$(NAME): $(OBJ) $(LIB_LIBFT) $(LIB_FT_PRINTF) $(LIB_GET_NEXT_LINE)
	$(CC) $(CFLAGS) $(OBJ) $(LIB_COMBINE) -Lmlx_linux  -L/usr/lib \
	-Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@ 

# -------------------------- FOR LINUX ------------------------------

# -------------------------- FOR MACOS ------------------------------
#
# $(NAME): $(OBJ) $(LIB_LIBFT) $(LIB_FT_PRINTF) $(LIB_GET_NEXT_LINE)
# 	$(CC) $(CFLAGS) $(OBJ) $(LIB_COMBINE) -Lminilibx_mac -lmlx -framework OpenGL -framework AppKit \
# 	-o $(NAME)
#
# %.o: %.c
# 	$(CC) -Wall -Wextra -Werror -Iminilibx_mac -c $< -o $@
#
# -------------------------- FOR MACOS ------------------------------

$(LIB_LIBFT):
	@make -C libft 

$(LIB_FT_PRINTF):
	@make -C ft_printf

$(LIB_GET_NEXT_LINE):
	@make -C get_next_line 

clean: 
	rm -f $(OBJ)
	@make clean -C libft 
	@make clean -C ft_printf 
	@make clean -C get_next_line 

fclean: clean
	rm -f $(NAME)
	@make fclean -C libft 
	@make fclean -C ft_printf 
	@make fclean -C get_next_line 

re: fclean all 
	@make re -C libft 
	@make re -C ft_printf 
	@make re -C get_next_line

norm:
	norminette libft
	norminette ft_printf
	norminette get_next_line
	norminette so_long_mandatory

.PHONY: clean fclean re all norm
