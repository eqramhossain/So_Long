/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:21:45 by ehossain          #+#    #+#             */
/*   Updated: 2025/03/19 11:30:30 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_scan_player(t_map *map);

int	ft_on_destroy(t_map *map)
{
	ft_destroy_image(map);
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	mlx_destroy_display(map->mlx_ptr);
	ft_freeup(map->full_map);
	ft_freeup(map->copy_map);
	ft_free(map);
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_on_keypress(int keycode, t_map *map)
{
	ft_scan_player(map);
	if (keycode == ESC)
		ft_on_destroy(map);
	else if (map->e_check == 1)
		ft_on_destroy(map);
	else if (keycode == UP)
		ft_move_up(map);
	else if (keycode == DOWN)
		ft_move_down(map);
	else if (keycode == LEFT)
		ft_move_left(map);
	else if (keycode == RIGHT)
		ft_move_right(map);
	return (0);
}

static void	ft_scan_player(t_map *map)
{
	ft_inisialize(&map->player_pos.x, &map->player_pos.y);
	while (map->player_pos.x < map->row)
	{
		map->player_pos.y = 0;
		while (map->player_pos.y < map->column)
		{
			if (map->copy_map[map->player_pos.x][map->player_pos.y] == 'P')
				return ;
			map->player_pos.y++;
		}
		map->player_pos.x++;
	}
}
