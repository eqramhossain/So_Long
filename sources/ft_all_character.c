/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_character.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:04:56 by ehossain          #+#    #+#             */
/*   Updated: 2025/03/06 16:45:37 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_count_character(t_map *map);
static void	ft_error_all_character(char *str, t_map *map);

void	ft_is_all_character_present(t_map *map)
{
	ft_count_character(map);
	if (map->collects < 1)
		ft_error_all_character("There is nothing to collect in the map.", map);
	if (map->exits < 1)
		ft_error_all_character("There is no exit in the map.", map);
	if (map->player < 1)
		ft_error_all_character("There is no player in the map.", map);
	if (map->exits > 1)
		ft_error_all_character("There is more than one exit in the map.", map);
	if (map->player > 1)
		ft_error_all_character("There is more than one player in the map.",
			map);
}

static void	ft_count_character(t_map *map)
{
	t_row_column	tab;

	ft_inisialize(&tab.row, &tab.column);
	while (map->full_map[tab.row])
	{
		tab.column = 0;
		while (map->full_map[tab.row][tab.column])
		{
			if (map->full_map[tab.row][tab.column] == '1')
				map->walls++;
			if (map->full_map[tab.row][tab.column] == '0')
				map->empty_spaces++;
			if (map->full_map[tab.row][tab.column] == 'C')
				map->collects++;
			if (map->full_map[tab.row][tab.column] == 'P')
			{
				map->player_pos.x = tab.row;
				map->player_pos.y = tab.column;
				map->player++;
			}
			if (map->full_map[tab.row][tab.column] == 'E')
				map->exits++;
			tab.column++;
		}
		tab.row++;
	}
}

static void	ft_error_all_character(char *str, t_map *map)
{
	ft_putstr_fd("\e[31m❌ERROR❌:\n", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\e[0m\n", 2);
	if (map->full_map)
		ft_freeup(map->full_map);
	if (map->copy_map)
		ft_freeup(map->copy_map);
	ft_free_exit(map);
}
