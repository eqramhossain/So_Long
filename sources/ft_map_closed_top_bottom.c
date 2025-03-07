/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_closed_top_bottom.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:04:45 by ehossain          #+#    #+#             */
/*   Updated: 2025/03/06 14:23:54 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void		ft_is_closed_top_bottom(t_map *map);
static void	ft_error_top(t_map *map);
static void	ft_error_bottom(t_map *map);

void	ft_is_closed_top_bottom(t_map *map)
{
	int		i;
	char	*top_line;
	char	*bottom_line;

	i = 0;
	top_line = map->full_map[0];
	bottom_line = map->full_map[map->row - 1];
	while (top_line[i] && i < (map->column - 1))
	{
		if (top_line[i] != '1')
			ft_error_top(map);
		i++;
	}
	i = 0;
	while (bottom_line[i] && i < (map->column - 1))
	{
		if (bottom_line[i] != '1')
			ft_error_bottom(map);
		i++;
	}
}

static void	ft_error_top(t_map *map)
{
	ft_putstr_fd("\e[31m❌ERROR❌:\n", 2);
	ft_putstr_fd("The map isn't enclosed on the top", 2);
	ft_putstr_fd("\e[0m\n", 2);
	if (map->full_map)
		ft_freeup(map->full_map);
	if (map->copy_map)
		ft_freeup(map->copy_map);
	ft_free_exit(map);
}

static void	ft_error_bottom(t_map *map)
{
	ft_putstr_fd("\e[31m❌ERROR❌:\n", 2);
	ft_putstr_fd("The map isn't enclosed on the bottom.", 2);
	ft_putstr_fd("\e[0m\n", 2);
	if (map->full_map)
		ft_freeup(map->full_map);
	if (map->copy_map)
		ft_freeup(map->copy_map);
	ft_free_exit(map);
}
