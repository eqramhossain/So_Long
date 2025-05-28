/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:34:01 by ehossain          #+#    #+#             */
/*   Updated: 2025/03/31 16:57:13 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_last_dance(t_map *map, t_row_column *new);

void	ft_win(t_map *map, t_row_column *new)
{
	ft_last_dance(map, new);
	ft_destroy_image(map);
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	mlx_destroy_display(map->mlx_ptr);
	ft_freeup(map->full_map);
	ft_freeup(map->copy_map);
	ft_free(map);
	ft_printf("YOU WON");
	exit(EXIT_SUCCESS);
	return ;
}

static void	ft_last_dance(t_map *map, t_row_column *new)
{
	map->copy_map[map->player_pos.x][map->player_pos.y] = FLOOR;
	map->copy_map[new->row][new->column] = EXIT_OPEN_PLAYER;
	map->player_pos.x = new->row;
	ft_redraw_map(map);
	map->move++;
	ft_printf("Move count = %d\n", map->move);
}
