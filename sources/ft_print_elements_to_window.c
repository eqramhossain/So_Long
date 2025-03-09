/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_elements_to_window.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:48:57 by ehossain          #+#    #+#             */
/*   Updated: 2025/03/09 16:23:54 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_print_wall_empty(t_map *map);

void	ft_print_elements_to_window(t_map *map)
{
	t_row_column	tab;

	ft_inisialize(&tab.row, &tab.column);
	ft_print_wall_empty(map);
	while (map->copy_map[tab.row])
	{
		tab.column = 0;
		while (map->copy_map[tab.row][tab.column])
		{
			if (map->copy_map[tab.row][tab.column] == 'P')
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
					map->img.main_img, tab.column * 64, tab.row * 64);
			else if (map->copy_map[tab.row][tab.column] == 'E')
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
					map->img.door_close_img, tab.column * 64, tab.row * 64);
			else if (map->copy_map[tab.row][tab.column] == 'C')
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
					map->img.collect_img, tab.column * 64, tab.row * 64);
			tab.column++;
		}
		tab.row++;
	}
}

static void	ft_print_wall_empty(t_map *map)
{
	t_row_column	tab;

	ft_inisialize(&tab.row, &tab.column);
	while (map->copy_map[tab.row])
	{
		tab.column = 0;
		while (map->copy_map[tab.row][tab.column])
		{
			if (map->copy_map[tab.row][tab.column] == '1')
			{
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
					map->img.wall_img, tab.column * 64, tab.row * 64);
			}
			else if (map->copy_map[tab.row][tab.column] == '0')
			{
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
					map->img.empty_img, tab.column * 64, tab.row * 64);
			}
			tab.column++;
		}
		tab.row++;
	}
}
