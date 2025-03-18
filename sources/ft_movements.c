/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:28:33 by ehossain          #+#    #+#             */
/*   Updated: 2025/03/18 12:04:33 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_tile(t_map *map, int row, int column, char tile)
{
	if (tile == EMPTY)
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.empty_img,
			row * TILE_SIZE, column * TILE_SIZE);
	else if (tile == EXIT)
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->img.door_open_img, row * TILE_SIZE, column * TILE_SIZE);
	else if (tile == MAIN)
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.main_img,
			row * TILE_SIZE, column * TILE_SIZE);
}

void	ft_move_up(t_map *map)
{
	t_row_column	new;

	new.row = map->player_pos.x - 1;
	new.column = map->player_pos.y;
	if (map->copy_map[new.row][new.column] == WALL)
		return ;
	map->copy_map[map->player_pos.x][map->player_pos.y] = '0';
	map->copy_map[new.row][new.column] = 'P';
	map->player_pos.x = new.row;
	ft_print_elements_to_window(map);
	map->move++;
	printf("Move count = %d\n", map->move);
}

void	ft_move_down(t_map *map)
{
	t_row_column	new;

	new.row = map->player_pos.x + 1;
	new.column = map->player_pos.y;
	if (map->copy_map[new.row][new.column] == WALL)
		return ;
	map->copy_map[map->player_pos.x][map->player_pos.y] = '0';
	map->copy_map[new.row][new.column] = 'P';
	map->player_pos.x = new.row;
	ft_print_elements_to_window(map);
	map->move++;
	printf("Move count = %d\n", map->move);
}

void	ft_move_left(t_map *map)
{
	t_row_column	new;

	new.row = map->player_pos.x;
	new.column = map->player_pos.y - 1;
	if (map->copy_map[new.row][new.column] == WALL)
		return ;
	map->copy_map[map->player_pos.x][map->player_pos.y] = '0';
	map->copy_map[new.row][new.column] = 'P';
	map->player_pos.y = new.column;
	ft_print_elements_to_window(map);
	map->move++;
	printf("Move count = %d\n", map->move);
}

void	ft_move_right(t_map *map)
{
	t_row_column	new;

	new.row = map->player_pos.x;
	new.column = map->player_pos.y + 1;
	if (map->copy_map[new.row][new.column] == WALL)
		return ;
	map->copy_map[map->player_pos.x][map->player_pos.y] = '0';
	map->copy_map[new.row][new.column] = 'P';
	map->player_pos.y = new.column;
	ft_print_elements_to_window(map);
	map->move++;
	printf("Move count = %d\n", map->move);
}
