/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xpm_to_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:04:11 by ehossain          #+#    #+#             */
/*   Updated: 2025/03/31 16:13:35 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_xpm_to_image(t_map *map)
{
	int	width;
	int	height;

	width = 50;
	height = 50;
	map->img.wall_img = mlx_xpm_file_to_image(map->mlx_ptr,
			"images/so_long_ekram/WALL.xpm", &width, &height);
	map->img.empty_img = mlx_xpm_file_to_image(map->mlx_ptr,
			"images/so_long_ekram/empty.xpm", &width, &height);
	map->img.collect_img = mlx_xpm_file_to_image(map->mlx_ptr,
			"images/so_long_ekram/collect.xpm", &width, &height);
	map->img.main_img = mlx_xpm_file_to_image(map->mlx_ptr,
			"images/so_long_ekram/main.xpm", &width, &height);
	map->img.door_close_img = mlx_xpm_file_to_image(map->mlx_ptr,
			"images/so_long_ekram/door_close.xpm", &width, &height);
	map->img.door_close_player_img = mlx_xpm_file_to_image(map->mlx_ptr,
			"images/so_long_ekram/door_close_player.xpm", &width, &height);
	map->img.door_open_img = mlx_xpm_file_to_image(map->mlx_ptr,
			"images/so_long_ekram/door_open.xpm", &width, &height);
	map->img.door_open_player_img = mlx_xpm_file_to_image(map->mlx_ptr,
			"images/so_long_ekram/door_open_player.xpm", &width, &height);
}
