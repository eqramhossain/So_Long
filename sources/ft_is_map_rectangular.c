/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_map_rectangular.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:55:35 by ehossain          #+#    #+#             */
/*   Updated: 2025/03/31 11:18:52 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_error_rectangular(t_map *map);
static void	ft_error_minimum(t_map *map);

void	ft_is_map_rectangular(t_map *map)
{
	int	first_line;

	first_line = ft_strlen(map->full_map[0]);
	while (map->full_map[map->row])
	{
		map->column = 0;
		while (map->full_map[map->row][map->column])
			map->column++;
		if (first_line != map->column)
			ft_error_rectangular(map);
		map->row++;
	}
	if (map->row == 2)
		ft_error_minimum(map);
}

static void	ft_error_rectangular(t_map *map)
{
	ft_putstr_fd("\e[31mERROR:\n", 2);
	ft_putstr_fd("The map is not rectangular.", 2);
	ft_putstr_fd("\e[0m\n", 2);
	if (map->full_map)
		ft_freeup(map->full_map);
	if (map->copy_map)
		ft_freeup(map->copy_map);
	ft_free_exit(map);
}

static void	ft_error_minimum(t_map *map)
{
	ft_putstr_fd("\e[31mERROR:\n", 2);
	ft_putstr_fd("The map is to small to be a map", 2);
	ft_putstr_fd("\e[0m\n", 2);
	if (map->full_map)
		ft_freeup(map->full_map);
	if (map->copy_map)
		ft_freeup(map->copy_map);
	ft_free_exit(map);
}
