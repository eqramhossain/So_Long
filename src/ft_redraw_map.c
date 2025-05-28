/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redraw_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:59:49 by ehossain          #+#    #+#             */
/*   Updated: 2025/03/31 17:02:24 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_helper(t_map *map);

void	ft_redraw_map(t_map *map)
{
	ft_print_wall_empty(map);
	ft_print_elements_to_window(map);
	ft_helper(map);
}

static void	ft_helper(t_map *map)
{
	t_row_column	tab;

	ft_inisialize(&tab.row, &tab.column);
	while (map->copy_map[tab.row])
	{
		tab.column = 0;
		while (map->copy_map[tab.row][tab.column])
		{
			if (map->copy_map[tab.row][tab.column] == EXIT_CLOSE_PLAYER)
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
					map->img.door_close_player_img, tab.column * TILE_SIZE,
					tab.row * TILE_SIZE);
			else if (map->copy_map[tab.row][tab.column] == EXIT_OPEN)
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
					map->img.door_open_img, tab.column * TILE_SIZE, tab.row
					* TILE_SIZE);
			else if (map->copy_map[tab.row][tab.column] == EXIT_OPEN_PLAYER)
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
					map->img.door_open_img, tab.column * TILE_SIZE, tab.row
					* TILE_SIZE);
			tab.column++;
		}
		tab.row++;
	}
}
