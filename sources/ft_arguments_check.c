/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arguments_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:01:48 by ehossain          #+#    #+#             */
/*   Updated: 2025/03/02 15:46:43 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_arguments_check(t_map *map)
{
	map->file_name = map->av[1];
	if (map->ac == 1)
	{
		ft_error("Please provide a file");
		exit(EXIT_FAILURE);
	}
	else if (map->ac > 2)
	{
		ft_error("Multiple files");
		exit(EXIT_FAILURE);
	}
	else if (ft_is_file_ok(map) == 1)
		exit(EXIT_FAILURE);
	else if (ft_read_map(map) == 1)
	{
		ft_error("ft_read_map failed. Good Luck!");
		exit(EXIT_FAILURE);
	}
	else if (ft_is_map_rectangular(map->full_map) == 1)
		exit(EXIT_FAILURE);
	else if (ft_is_map_closed(map->full_map) == 1)
		exit(EXIT_FAILURE);
	else if (ft_is_all_character_present(map) == 1)
		exit(EXIT_FAILURE);
	ft_flood_fill(map->full_map);
	if (ft_validpath_check(map->full_map, map->copy_map) == 0)
		printf("This map have a valid path\n");
	else if (ft_validpath_check(map->full_map, map->copy_map) == 1)
		printf("This map have a valid path\n");
	for (int i = 0; map->full_map[i]; i++)
		printf("full_map[i] = %s\n", map->full_map[i]);
	for (int i = 0; map->copy_map[i]; i++)
		printf("full_map[i] = %s\n", map->copy_map[i]);
}

int	ft_is_file_ok(t_map *map)
{
	map->len_file_name = ft_strlen(map->file_name);
	map->fd = open(map->file_name, O_RDONLY);
	if (map->fd == -1)
	{
		ft_error("File not found / permission denied");
		return (close(map->fd), 1);
	}
	if (!ft_strnstr(map->file_name, ".ber", map->len_file_name))
	{
		ft_error("Expected file format example.ber");
		return (close(map->fd), 1);
	}
	map->next_line = get_next_line(map->fd);
	if (map->next_line == NULL)
	{
		ft_error("File is empty");
		return (free(map->next_line), close(map->fd), 1);
	}
	if (map->next_line[0] == '\n')
	{
		ft_error("File has a newline at the beginning");
		return (free(map->next_line), close(map->fd), 1);
	}
	return (free(map->next_line), close(map->fd), 0);
}

int	ft_read_map(t_map *map)
{
	map->fd = open(map->file_name, O_RDONLY);
	map->next_line = ft_calloc_gnl(1, sizeof(char));
	if (!map->next_line)
		return (1);
	map->tmp_map = ft_calloc_gnl(1, sizeof(char));
	if (!map->tmp_map)
		return (free(map->next_line), 1);
	while (map->next_line != NULL)
	{
		free(map->next_line);
		map->next_line = get_next_line(map->fd);
		if (!map->next_line)
			break ;
		map->tmp_map = ft_str_free_join_gnl(map->tmp_map, map->next_line);
		if (!map->tmp_map)
			return (free(map->next_line), 1);
	}
	map->full_map = ft_split(map->tmp_map, '\n');
	if (!map->full_map)
		return (free(map->next_line), free(map->tmp_map), close(map->fd), 1);
	return (free(map->next_line), free(map->tmp_map), close(map->fd), 0);
}

int	ft_is_map_rectangular(char **map)
{
	t_count	tab;
	int		len;

	ft_inisialize(&tab.i, &tab.j);
	len = ft_strlen(map[tab.i]);
	while (map[tab.i][tab.j])
	{
		tab.j = 0;
		while (map[tab.i][tab.j])
		{
			tab.j++;
		}
		if (tab.j != len)
			return (ft_error("This map is not rectangular"), 1);
		tab.i++;
	}
	return (0);
}

int	ft_is_map_closed(char **map)
{
	t_count	tab;

	ft_inisialize(&tab.i, &tab.j);
	while (map[tab.i])
	{
		tab.j = 0;
		while (map[tab.i][tab.j])
			tab.j++;
		tab.i++;
	}
	if (tab.i < 3)
		return (ft_error("This map is too small to be a map"), 1);
	else
	{
		if (ft_is_closed_top_bottom(map, &tab) == 1)
			return (1);
		if (ft_is_closed_left_right(map, &tab) == 1)
			return (1);
	}
	return (0);
}

int	ft_is_closed_top_bottom(char **full_map, t_count *tab)
{
	int	i;

	i = 0;
	while (full_map[0][i] && i < tab->j)
	{
		if (full_map[0][i] != '1')
			return (ft_error("Map isn't closed on top"), 1);
		i++;
	}
	i = 0;
	while (full_map[tab->i - 1][i] && i < tab->j)
	{
		if (full_map[tab->i - 1][i] != '1')
			return (ft_error("Map isn't closed on bottom"), 1);
		i++;
	}
	return (0);
}

int	ft_is_closed_left_right(char **full_map, t_count *tab)
{
	int	row;
	int	column;

	row = 0;
	column = tab->j;
	while (full_map[row])
	{
		if (full_map[row][0] != '1' || full_map[row][column - 1] != '1')
			return (ft_error("Map isn't closed by walls on left/right"), 1);
		row++;
	}
	return (0);
}

int	ft_is_all_character_present(t_map *map)
{
	int		row;
	int		column;
	char	**full_map;

	ft_inisialize(&row, &column);
	ft_inisialize_t_map(map);
	full_map = ft_strstrcpy(map);
	while (full_map[row])
	{
		column = 0;
		while (full_map[row][column])
		{
			if (full_map[row][column] == '1')
				map->walls++;
			if (full_map[row][column] == '0')
				map->empty_spaces++;
			if (full_map[row][column] == 'E')
				map->exits++;
			if (full_map[row][column] == 'P')
				map->players++;
			if (full_map[row][column] == 'C')
				map->collects++;
			if (full_map[row][column] != '1' && full_map[row][column] != '0'
				&& full_map[row][column] != 'E' && full_map[row][column] != 'P'
				&& full_map[row][column] != 'C' && full_map[row][column] != '\0'
				&& full_map[row][column] != '\n')
			{
				return (ft_error("There is a unknown charecter found"), 1);
			}
			column++;
		}
		row++;
	}
	if (map->exits != 1)
		return (ft_error("There is more/less than one exit"), 1);
	if (map->players != 1)
		return (ft_error("There is more/less than one players"), 1);
	if (map->collects < 1)
		return (ft_error("This map has nothing to collect"), 1);
	return (0);
}

int	ft_flood_fill(char **full_map)
{
	t_count		tab;
	t_position	player_pos;

	ft_inisialize(&tab.i, &tab.j);
	while (full_map[tab.i])
	{
		tab.j = 0;
		while (full_map[tab.i][tab.j])
		{
			if (full_map[tab.i][tab.j] == 'P')
			{
				player_pos.x = tab.i;
				player_pos.y = tab.j;
			}
			tab.j++;
		}
		tab.i++;
	}
	ft_flood_fill_verif(full_map, player_pos, tab);
	return (0);
}

void	ft_flood_fill_verif(char **map, t_position player_pos, t_count count)
{
	if (player_pos.x < 0 || player_pos.x >= count.i || player_pos.y < 0
		|| player_pos.y >= count.j || ((map[player_pos.x][player_pos.y] != '0')
			&& (map[player_pos.x][player_pos.y] != 'C')
			&& (map[player_pos.x][player_pos.y] != 'E')
			&& (map[player_pos.x][player_pos.y] != 'P')))
		return ;
	map[player_pos.x][player_pos.y] = 'F';
	ft_flood_fill_verif(map, (t_position){player_pos.x + 1, player_pos.y},
		count);
	ft_flood_fill_verif(map, (t_position){player_pos.x - 1, player_pos.y},
		count);
	ft_flood_fill_verif(map, (t_position){player_pos.x, player_pos.y + 1},
		count);
	ft_flood_fill_verif(map, (t_position){player_pos.x, player_pos.y - 1},
		count);
}

int	ft_validpath_check(char **new_map, char **old_map)
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
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
