/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_closed_left_right.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:26:56 by ehossain          #+#    #+#             */
/*   Updated: 2025/03/31 15:18:55 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_error_left_right(t_map *map);

void	ft_is_closed_left_right(t_map *map)
{
	t_row_column	tab;

	tab.row = 1;
	tab.column = map->column;
	while (map->full_map[tab.row])
	{
		if (map->full_map[tab.row][0] != '1'
			|| map->full_map[tab.row][tab.column - 1] != '1')
			ft_error_left_right(map);
		tab.row++;
	}
}

static void	ft_error_left_right(t_map *map)
{
	ft_putstr_fd("\e[31mERROR:\n", 2);
	ft_putstr_fd("The map isn't enclosed on the left/right.", 2);
	ft_putstr_fd("\e[0m\n", 2);
	if (map->full_map)
		ft_freeup(map->full_map);
	if (map->copy_map)
		ft_freeup(map->copy_map);
	ft_free_exit(map);
}
