/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_path_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:28:50 by ehossain          #+#    #+#             */
/*   Updated: 2025/03/03 15:28:58 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	ft_flood_fill(char **full_map)
// {
// 	t_count		tab;
// 	t_position	player_pos;
//
// 	ft_inisialize(&tab.i, &tab.j);
// 	while (full_map[tab.i])
// 	{
// 		tab.j = 0;
// 		while (full_map[tab.i][tab.j])
// 		{
// 			if (full_map[tab.i][tab.j] == 'P')
// 			{
// 				player_pos.x = tab.i;
// 				player_pos.y = tab.j;
// 			}
// 			tab.j++;
// 		}
// 		tab.i++;
// 	}
// 	ft_flood_fill_verif(full_map, player_pos, tab);
// 	return (0);
// }
//
// void	ft_flood_fill_verif(char **map, t_position player_pos, t_count count)
// {
// 	if (player_pos.x < 0 || player_pos.x >= count.i || player_pos.y < 0
// 		|| player_pos.y >= count.j || ((map[player_pos.x][player_pos.y] != '0')
// 			&& (map[player_pos.x][player_pos.y] != 'C')
// 			&& (map[player_pos.x][player_pos.y] != 'E')
// 			&& (map[player_pos.x][player_pos.y] != 'P')))
// 		return ;
// 	map[player_pos.x][player_pos.y] = 'F';
// 	ft_flood_fill_verif(map, (t_position){player_pos.x + 1, player_pos.y},
// 		count);
// 	ft_flood_fill_verif(map, (t_position){player_pos.x - 1, player_pos.y},
// 		count);
// 	ft_flood_fill_verif(map, (t_position){player_pos.x, player_pos.y + 1},
// 		count);
// 	ft_flood_fill_verif(map, (t_position){player_pos.x, player_pos.y - 1},
// 		count);
// }
//
// int	ft_validpath_check(char **new_map, char **old_map)
// {
// 	int	i;
// 	int	j;
//
// 	ft_inisialize(&i, &j);
// 	while (old_map[i])
// 	{
// 		j = 0;
// 		while (old_map[i][j])
// 		{
// 			if (old_map[i][j] == 'C' || old_map[i][j] == 'E')
// 			{
// 				if (new_map[i][j] != 'F')
// 					return (1);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }
