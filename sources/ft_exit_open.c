/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_open.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:29:19 by ehossain          #+#    #+#             */
/*   Updated: 2025/03/21 18:36:57 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit_open(t_map *map)
{
	t_row_column	tab;

	ft_inisialize(&tab.row, &tab.column);
	while (map->copy_map[tab.row])
	{
		tab.column = 0;
		while (map->copy_map[tab.row][tab.column])
		{
			if (map->copy_map[tab.row][tab.column] == EXIT)
				map->copy_map[tab.row][tab.column] = EXIT_OPEN;
			tab.column++;
		}
		tab.row++;
	}
	ft_redraw_map(map);
}
