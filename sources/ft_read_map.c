/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:29:52 by ehossain          #+#    #+#             */
/*   Updated: 2025/03/03 15:25:09 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_read_map(char *file, t_map *map)
{
	int		fd;
	char	*tmp_map;
	char	*next_line;

	fd = open(file, O_RDONLY);
	tmp_map = ft_calloc(1, sizeof(char));
	if (!tmp_map)
		ft_error_exit("Malloc failed (ft_read_map)");
	while (next_line != NULL)
	{
		next_line = get_next_line(fd);
		if (next_line == NULL)
			break ;
		tmp_map = ft_str_free_join_gnl(tmp_map, next_line);
		if (!tmp_map)
		{
			free(next_line);
			ft_error_exit("Malloc failed (ft_read_map)");
		}
		free(next_line);
	}
	map->full_map = ft_split(tmp_map, '\n');
	map->copy_map = ft_split(tmp_map, '\n');
	if (!map->full_map || !map->copy_map)
	{
		free(tmp_map);
		free()
	}
	free(next_line);
	free(tmp_map);
	close(fd);
}
