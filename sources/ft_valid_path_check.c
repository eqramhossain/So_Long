/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_path_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:28:50 by ehossain          #+#    #+#             */
/*   Updated: 2025/03/07 01:27:51 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_validpath_check(char **new_map, char **old_map, t_map *map);
static void	ft_flood_fill(char **map, t_player player_pos, int row, int column);
static void	ft_error_valid_path(t_map *map);

void	ft_flood_fill_verif(t_map *map)
{
	ft_flood_fill(map->full_map, map->player_pos, map->row, map->column);
	ft_validpath_check(map->full_map, map->copy_map, map);
}

static void	ft_flood_fill(char **map, t_player player_pos, int row, int column)
{
	if (player_pos.x < 0 || player_pos.x >= row || player_pos.y < 0
		|| player_pos.y >= column || ((map[player_pos.x][player_pos.y] != '0')
			&& (map[player_pos.x][player_pos.y] != 'C')
			&& (map[player_pos.x][player_pos.y] != 'E')
			&& (map[player_pos.x][player_pos.y] != 'P')))
		return ;
	map[player_pos.x][player_pos.y] = 'F';
	ft_flood_fill(map, (t_player){player_pos.x + 1, player_pos.y}, row, column);
	ft_flood_fill(map, (t_player){player_pos.x - 1, player_pos.y}, row, column);
	ft_flood_fill(map, (t_player){player_pos.x, player_pos.y + 1}, row, column);
	ft_flood_fill(map, (t_player){player_pos.x, player_pos.y - 1}, row, column);
}

static void	ft_validpath_check(char **new_map, char **old_map, t_map *map)
{
	int	i;
	int	j;

	ft_inisialize(&i, &j);
	while (old_map[i])
	{
		j = 0;
		while (old_map[i][j])
		{
			if (old_map[i][j] == 'C' || old_map[i][j] == 'E')
			{
				if (new_map[i][j] != 'F')
					ft_error_valid_path(map);
			}
			j++;
		}
		i++;
	}
}

static void	ft_error_valid_path(t_map *map)
{
	ft_putstr_fd("\e[31m❌ERROR❌:\n", 2);
	ft_putstr_fd("Map does not have a valid path.", 2);
	ft_putstr_fd("\e[0m\n", 2);
	if (map->full_map)
		ft_freeup(map->full_map);
	if (map->copy_map)
		ft_freeup(map->copy_map);
	ft_free_exit(map);
}
