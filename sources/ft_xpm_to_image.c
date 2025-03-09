/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xpm_to_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:04:11 by ehossain          #+#    #+#             */
/*   Updated: 2025/03/09 12:24:50 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_xpm_to_image(void *ptr_mlx, t_img *img)
{
	int	width;
	int	height;

	width = 32;
	height = 32;
	img->wall_img = mlx_xpm_file_to_image(ptr_mlx, WALL, &width, &height);
	img->empty_img = mlx_xpm_file_to_image(ptr_mlx, EMPTY, &width, &height);
	img->collect_img = mlx_xpm_file_to_image(ptr_mlx, COLLECT, &width, &height);
	img->main_img = mlx_xpm_file_to_image(ptr_mlx, MAIN, &width, &height);
	img->door_close_img = mlx_xpm_file_to_image(ptr_mlx, DOOR_CLOSE, &width,
			&height);
	img->door_open_img = mlx_xpm_file_to_image(ptr_mlx, DOOR_OPEN, &width,
			&height);
}
