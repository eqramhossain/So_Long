/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:55:23 by ehossain          #+#    #+#             */
/*   Updated: 2025/02/22 18:55:51 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	main(int ac, char *av[])
// {
// 	void	*mlx_ptr;
// 	void	*mlx_win;
// 	void	*ptr_image;
// 	int		width_head;
// 	int		height_head;
// 	int		tile_size;
// 	int		tiles_x;
// 	int		tiles_y;
// 	int		win_width;
// 	int		win_height;
// 	int		i;
// 	int		j;
//
// 	(void)ac;
// 	tiles_x = 25;
// 	tiles_y = 25;
// 	tile_size = 32;
// 	win_width = tiles_x * tile_size;
// 	win_height = tiles_y * tile_size;
// 	width_head = 32;
// 	height_head = 32;
// 	mlx_ptr = mlx_init();
// 	if (!mlx_ptr)
// 		return (0);
// 	mlx_win = mlx_new_window(mlx_ptr, win_width, win_height, "so_long");
// 	ptr_image = mlx_xpm_file_to_image(mlx_ptr, av[1], &width_head,
// 			&height_head);
// 	i = 0;
// 	while (i < win_width)
// 	{
// 		mlx_put_image_to_window(mlx_ptr, mlx_win, ptr_image, i, 0);
// 		mlx_put_image_to_window(mlx_ptr, mlx_win, ptr_image, i, win_height
// 			- tile_size);
// 		i = i + tile_size;
// 	}
// 	j = 0;
// 	while (j < win_height)
// 	{
// 		mlx_put_image_to_window(mlx_ptr, mlx_win, ptr_image, 0, j);
// 		mlx_put_image_to_window(mlx_ptr, mlx_win, ptr_image, win_width
// 			- tile_size, j);
// 		j = j + tile_size;
// 	}
// 	mlx_loop(mlx_ptr);
// 	return (0);
// }
