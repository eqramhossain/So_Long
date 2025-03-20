/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements_left_right.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:35:29 by ehossain          #+#    #+#             */
/*   Updated: 2025/03/20 15:21:36 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_movements_left_right(t_map *map, char signe);

static void	ft_movements_left_right(t_map *map, char signe)
{
	t_row_column	new;

	new.row = map->player_pos.x;
	if (signe == '-')
		new.column = map->player_pos.y - 1;
	if (signe == '+')
		new.column = map->player_pos.y + 1;
	if (map->copy_map[new.row][new.column] == WALL)
		return ;
	if (map->copy_map[new.row][new.column] == COLLECT)
		map->collects--;
	if (map->copy_map[new.row][new.column] == EXIT)
		return (ft_print_exit_player(map), );
	map->copy_map[map->player_pos.x][map->player_pos.y] = FLOOR;
	map->copy_map[new.row][new.column] = PLAYER;
	map->player_pos.y = new.column;
	ft_print_elements_to_window(map);
	map->move++;
	ft_printf("Move count = %d\n", map->move);
}

void	ft_move_left(t_map *map)
{
	ft_movements_left_right(map, '-');
}

void	ft_move_right(t_map *map)
{
	ft_movements_left_right(map, '+');
}
