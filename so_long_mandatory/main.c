/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:28:55 by ehossain          #+#    #+#             */
/*   Updated: 2025/02/22 14:26:12 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*ptr_image;
	int		width;
	int		height;

	width = 256;
	height = 256;
	mlx_ptr = mlx_init();
	/* 	this function uses malloc you have to protect your malloc */
	if (!mlx_ptr)
		return (0);
	mlx_win = mlx_new_window(mlx_ptr, 1000, 1000, "so_long");
	mlx_pixel_put(mlx_ptr, mlx_win, 500, 500, 0xFF0000);
	mlx_clear_window(mlx_ptr, mlx_win);
	mlx_pixel_put(mlx_ptr, mlx_win, 500, 500, 0xFFFF00);
	mlx_clear_window(mlx_ptr, mlx_win);
	mlx_string_put(mlx_ptr, mlx_win, 500, 500, 0xFFFFFF, "hello world!");
	mlx_clear_window(mlx_ptr, mlx_win);
	ptr_image = mlx_xpm_file_to_image(mlx_ptr, "../xpm_images/block.xpm",
			&width, &height);
	mlx_put_image_to_window(mlx_ptr, mlx_win, ptr_image, 500, 500);
	mlx_loop(mlx_ptr);
	printf("1 = %d\n", 1);
	return (0);
}

// if (ac != 2)
// {
// 	ft_printf("please provide a file\n");
// 	return (0);
// }
// if (!ft_fd_check(av[1]))
// {
// 	ft_printf("incorrect file format expected file format example.ber\n");
// 	return (0);
// }
