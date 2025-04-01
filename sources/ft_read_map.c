/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:29:52 by ehossain          #+#    #+#             */
/*   Updated: 2025/04/01 18:22:50 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_read_map(t_map *map)
{
	map->fd = open(map->filename, O_RDONLY);
	map->next_line = "";
	map->tmp_map = ft_calloc(1, sizeof(char));
	if (!map->tmp_map)
		return ;
	while (map->next_line != NULL)
	{
		map->next_line = get_next_line(map->fd);
		if (map->next_line == NULL)
			break ;
		map->tmp_map = ft_str_free_join_gnl(map->tmp_map, map->next_line);
		if (!map->tmp_map)
			ft_free_exit(map);
		free(map->next_line);
	}
	close(map->fd);
	ft_newline_check(map->tmp_map);
	map->full_map = ft_split(map->tmp_map, '\n');
	map->copy_map = ft_split(map->tmp_map, '\n');
	if (!map->full_map || !map->copy_map)
		ft_free_exit(map);
	free(map->tmp_map);
	map->tmp_map = NULL;
}
