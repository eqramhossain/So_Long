/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:17:45 by ehossain          #+#    #+#             */
/*   Updated: 2025/03/22 12:46:21 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_destroy_image(t_map *map)
{
	mlx_destroy_image(map->mlx_ptr, map->img.wall_img);
	mlx_destroy_image(map->mlx_ptr, map->img.empty_img);
	mlx_destroy_image(map->mlx_ptr, map->img.collect_img);
	mlx_destroy_image(map->mlx_ptr, map->img.main_img);
	mlx_destroy_image(map->mlx_ptr, map->img.door_close_img);
	mlx_destroy_image(map->mlx_ptr, map->img.door_close_player_img);
	mlx_destroy_image(map->mlx_ptr, map->img.door_open_img);
}
