/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xpm_to_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:04:11 by ehossain          #+#    #+#             */
/*   Updated: 2025/03/09 15:47:16 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_xpm_to_image(t_map *map)
{
	int	width;
	int	height;

	width = 50;
	height = 50;
	map->img.wall_img = mlx_xpm_file_to_image(map->mlx_ptr, WALL, &width,
			&height);
	map->img.empty_img = mlx_xpm_file_to_image(map->mlx_ptr, EMPTY, &width,
			&height);
	map->img.collect_img = mlx_xpm_file_to_image(map->mlx_ptr, COLLECT, &width,
			&height);
	map->img.main_img = mlx_xpm_file_to_image(map->mlx_ptr, MAIN, &width,
			&height);
	map->img.door_close_img = mlx_xpm_file_to_image(map->mlx_ptr, DOOR_CLOSE,
			&width, &height);
	map->img.door_open_img = mlx_xpm_file_to_image(map->mlx_ptr, DOOR_OPEN,
			&width, &height);
}
