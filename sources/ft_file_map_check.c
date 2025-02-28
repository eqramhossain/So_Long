/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_map_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:26:18 by ehossain          #+#    #+#             */
/*   Updated: 2025/02/28 09:42:30 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_file_map_check(char *file_name)
{
	char			*full_map;
	t_map			map;
	t_line_length	line_length;

	if (ft_is_file_ok(file_name) == 1)
		return (NULL);
	full_map = ft_read_map(file_name);
	if (full_map == NULL)
		return (free(full_map), NULL);
	else if (ft_is_map_rectangular(full_map, &line_length) == 1)
		return (free(full_map), NULL);
	else if (ft_is_map_closed(full_map) == 1)
		return (free(full_map), NULL);
	else if (ft_is_all_character_present(full_map, &map) == 1)
		return (free(full_map), NULL);
	else if (ft_flood_fill(full_map) == 1)
		return (NULL);
	return (full_map);
}

int	ft_is_file_ok(char *file_name)
{
	int		len;
	int		fd;
	char	*line;

	len = ft_strlen(file_name);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_print_error("File not found check if you have the permissions");
		return (close(fd), 1);
	}
	if (!ft_strnstr(file_name, ".ber", len))
	{
		ft_print_error("Expected file format example.ber");
		return (close(fd), 1);
	}
	line = get_next_line(fd);
	if (line == NULL)
	{
		ft_print_error("File is empty");
		free(line);
		return (close(fd), 1);
	}
	free(line);
	close(fd);
	return (0);
}

char	*ft_read_map(char *file_name)
{
	char	*next_line;
	char	*full_map;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (ft_print_error("File not found"), NULL);
	next_line = ft_calloc(1, sizeof(char));
	if (!next_line)
		return (NULL);
	full_map = ft_calloc(1, sizeof(char));
	if (!full_map)
		return (free(next_line), NULL);
	while (next_line != NULL)
	{
		free(next_line);
		next_line = get_next_line(fd);
		if (!next_line)
		{
			free(next_line);
			break ;
		}
		full_map = ft_str_free_join_gnl(full_map, next_line);
		if (!full_map)
			return (free(next_line), free(full_map), NULL);
	}
	return (close(fd), full_map);
}

int	ft_flood_fill(char *full_map)
{
	char		**map;
	t_position	player_pos;
	t_position	count;
	int			i;

	ft_inisialize(&count.x, &count.y);
	map = ft_split(full_map, '\n');
	if (!map)
		return (ft_freeup(map), 1);
	while (map[count.x])
	{
		count.y = 0;
		while (map[count.x][count.y])
		{
			if (map[count.x][count.y] == 'P')
			{
				player_pos.x = count.x;
				player_pos.y = count.y;
			}
			count.y++;
		}
		count.x++;
	}
	printf("x = %d\n", count.x);
	printf("y = %d\n", count.y);
	printf("player_pos.x = %d\n", player_pos.x);
	printf("player_pos.y = %d\n", player_pos.y);
	i = ft_flood_fill_verif(map, player_pos, count);
	printf("i = %d\n", i);
	return (0);
}

int	ft_flood_fill_verif(char **map, t_position player_pos, t_position count)
{
	if (player_pos.x < 0 || player_pos.x >= count.x || player_pos.y < 0
		|| player_pos.y >= count.y || ((map[player_pos.x][player_pos.y] != '0')
			&& (map[player_pos.x][player_pos.y] != 'C')
			&& (map[player_pos.x][player_pos.y] != 'E')
			&& (map[player_pos.x][player_pos.y] != 'P')))
		return (1);
	map[player_pos.x][player_pos.y] = 'F';
	ft_flood_fill_verif(map, (t_position){player_pos.x + 1, player_pos.y},
		count);
	ft_flood_fill_verif(map, (t_position){player_pos.x - 1, player_pos.y},
		count);
	ft_flood_fill_verif(map, (t_position){player_pos.x, player_pos.y + 1},
		count);
	ft_flood_fill_verif(map, (t_position){player_pos.x, player_pos.y - 1},
		count);
	return (0);
}
