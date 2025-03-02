/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 10:14:00 by ehossain          #+#    #+#             */
/*   Updated: 2025/03/02 11:09:33 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_strstrcpy(t_map *map)
{
	t_count	tab;
	int		i;

	i = 0;
	ft_inisialize(&tab.i, &tab.j);
	while (map->full_map[tab.i])
	{
		tab.j = 0;
		while (map->full_map[tab.i][tab.j])
			tab.j++;
		tab.i++;
	}
	map->copy_map = malloc(tab.i * sizeof(char *));
	if (!map->copy_map)
		return (NULL);
	while (i < tab.j)
	{
		map->copy_map[i] = malloc(tab.j * sizeof(char));
		if (!map->copy_map[i])
			return (NULL);
		i++;
	}
	ft_inisialize(&tab.i, &tab.j);
	while (map->full_map[tab.i])
	{
		tab.j = 0;
		while (map->full_map[tab.i][tab.j])
		{
			map->copy_map[tab.i][tab.j] = map->full_map[tab.i][tab.j];
			tab.j++;
		}
		map->copy_map[tab.i][tab.j] = '\0';
		tab.i++;
	}
	map->copy_map[tab.i] = NULL;
	return (map->copy_map);
}
