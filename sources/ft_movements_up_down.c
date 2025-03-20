/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements_up_down.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:28:33 by ehossain          #+#    #+#             */
/*   Updated: 2025/03/20 14:39:12 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_movements_up_down(t_map *map, char signe);

static void	ft_movements_up_down(t_map *map, char signe)
{
	t_row_column	new;

	if (signe == '-')
		new.row = map->player_pos.x - 1;
	if (signe == '+')
		new.row = map->player_pos.x + 1;
	new.column = map->player_pos.y;
	if (map->copy_map[new.row][new.column] == WALL)
		return ;
	if (map->copy_map[new.row][new.column] == COLLECT)
		map->collects--;
	map->copy_map[map->player_pos.x][map->player_pos.y] = FLOOR;
	map->copy_map[new.row][new.column] = PLAYER;
	map->player_pos.x = new.row;
	ft_print_elements_to_window(map);
	map->move++;
	ft_printf("Move count = %d\n", map->move);
}

void	ft_move_up(t_map *map)
{
	ft_movements_up_down(map, '-');
}

void	ft_move_down(t_map *map)
{
	ft_movements_up_down(map, '+');
}
