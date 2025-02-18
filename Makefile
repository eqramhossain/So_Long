# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/17 12:34:44 by ehossain          #+#    #+#              #
#    Updated: 2025/02/18 17:18:11 by ehossain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCE =  
NAME= so_long
CC= gcc
CFLAGS= -Wall -Wextra -Werror

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz \
	-o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@ 

clean:
	@make clean -C libft 
	@make clean -C ft_printf 
	@make clean -C get_next_line 

fclean: 
	@make fclean -C libft 
	@make fclean -C ft_printf 
	@make fclean -C get_next_line 

re: 
	@make re -C libft 
	@make re -C ft_printf 
	@make re -C get_next_line


.PHONY: clean fclean re all
