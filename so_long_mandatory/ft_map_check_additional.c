/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check_additional.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:16:48 by ehossain          #+#    #+#             */
/*   Updated: 2025/02/24 20:43:22 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_is_map_rectangular(char *full_map)
{
	int	i;
	int	current_line_length;
	int	first_line_length;

	i = 0;
	current_line_length = 0;
	first_line_length = 0;
	while (full_map[first_line_length] != '\n')
		first_line_length++;
	while (full_map[i])
	{
		if (full_map[i] == '\n' || full_map[i] == '\0')
		{
			if (first_line_length != current_line_length)
				ft_print_error("This map is not rectangular");
			else
				current_line_length = 0;
		}
		else
			current_line_length++;
		i++;
	}
	ft_is_map_closed(full_map);
	return (0);
}

int	ft_is_map_closed(char *full_map)
{
	int	line;
	int	count;

	line = 0;
	count = 0;
	while (full_map[count])
	{
		if (full_map[count] == '\n')
			line++;
		count++;
	}
	if (line < 3)
		ft_print_error("this map is too small to be a map");
	else
	{
		ft_is_closed_top_bottom(full_map, line, count / line);
		ft_is_closed_left_right(full_map, line, count / line);
	}
	return (0);
}

int	ft_is_closed_top_bottom(char *full_map, int line, int line_len)
{
	int	i;
	int	last_line_start;

	i = 0;
	last_line_start = line_len * (line - 1);
	while (i < line_len - 1)
	{
		if (full_map[i] != '1')
			ft_print_error("The top of the map is not enclosed by walls");
		i++;
	}
	i = 0;
	while (i < line_len - 1)
	{
		if (full_map[i + last_line_start] != '1')
			ft_print_error("The bottom of the map is not enclosed by walls");
		i++;
	}
	return (0);
}

int	ft_is_closed_left_right(char *full_map, int line, int line_len)
{
	int		row;
	int		start_index;
	t_map	map;

	row = 1;
	start_index = 0;
	while (row < line - 1)
	{
		start_index = row * line_len;
		if (full_map[start_index] != '1' \
				|| full_map[start_index + (line_len - 2)] != '1')
		{
			ft_print_error("Map is not surrounded by walls on left/right");
		}
		row++;
	}
	ft_is_all_character_present(full_map, &map);
	return (0);
}

int	ft_is_all_character_present(char *full_map, t_map *map)
{
	ft_initialize_t_map(map);
	while (full_map[map->i])
	{
		if (full_map[map->i] == '0')
			map->empty_space++;
		else if (full_map[map->i] == '1')
			map->wall++;
		else if (full_map[map->i] == 'C')
			map->collectible++;
		else if (full_map[map->i] == 'E')
			map->exit++;
		else if (full_map[map->i] == 'P')
			map->player++;
		map->i++;
	}
	if (map->collectible != 1)
		ft_print_error("Worng map. Map has more/less than one collectible.");
	if (map->exit != 1)
		ft_print_error("Worng map. Map has more/less than one exit.");
	if (map->player != 1)
		ft_print_error("Worng map. Map has more/less that one palyer.");
	return (0);
}
