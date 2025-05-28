/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements_up_down.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:28:33 by ehossain          #+#    #+#             */
/*   Updated: 2025/03/31 17:04:40 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_movements_up_down(t_map *map, t_row_column *new);
static void	ft_if_exit_close_player(t_map *map, t_row_column *new);
static void	ft_if_exit(t_map *map, t_row_column *new);

void	ft_move_up(t_map *map)
{
	t_row_column	new;

	new.row = map->player_pos.x - 1;
	new.column = map->player_pos.y;
	ft_movements_up_down(map, &new);
}

void	ft_move_down(t_map *map)
{
	t_row_column	new;

	new.row = map->player_pos.x + 1;
	new.column = map->player_pos.y;
	ft_movements_up_down(map, &new);
}

static void	ft_movements_up_down(t_map *map, t_row_column *new)
{
	if (map->copy_map[new->row][new->column] == WALL)
		return ;
	if (map->copy_map[new->row][new->column] == EXIT_OPEN)
		ft_win(map, new);
	if (map->copy_map[new->row][new->column] == COLLECT)
		map->collects--;
	if (map->copy_map[map->player_pos.x][map->player_pos.y]
			== EXIT_CLOSE_PLAYER)
	{
		ft_if_exit_close_player(map, new);
		return ;
	}
	if (map->copy_map[new->row][new->column] == EXIT)
	{
		ft_if_exit(map, new);
		return ;
	}
	map->copy_map[map->player_pos.x][map->player_pos.y] = FLOOR;
	map->copy_map[new->row][new->column] = PLAYER;
	map->player_pos.x = new->row;
	ft_redraw_map(map);
	map->move++;
	ft_printf("Move count = %d\n", map->move);
}

static void	ft_if_exit_close_player(t_map *map, t_row_column *new)
{
	map->copy_map[map->player_pos.x][map->player_pos.y] = EXIT;
	map->copy_map[new->row][new->column] = PLAYER;
	map->player_pos.x = new->row;
	ft_redraw_map(map);
	map->move++;
	ft_printf("Move count = %d\n", map->move);
}

static void	ft_if_exit(t_map *map, t_row_column *new)
{
	map->copy_map[map->player_pos.x][map->player_pos.y] = FLOOR;
	map->copy_map[new->row][new->column] = EXIT_CLOSE_PLAYER;
	map->player_pos.x = new->row;
	ft_redraw_map(map);
	map->move++;
	ft_printf("Move count = %d\n", map->move);
}
