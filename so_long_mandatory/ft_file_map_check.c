/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_map_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:26:18 by ehossain          #+#    #+#             */
/*   Updated: 2025/02/25 17:58:26 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_file_map_check(char *file_name)
{
	char	*full_map;
	t_map	map;

	if (ft_is_file_ok(file_name) == 1)
		return (NULL);
	full_map = ft_read_map(file_name);
	if (full_map == NULL)
		return (free(full_map), NULL);
	else if (ft_is_map_rectangular(full_map) == 1)
		return (free(full_map), NULL);
	else if (ft_is_map_closed(full_map) == 1)
		return (free(full_map), NULL);
	else if (ft_is_all_character_present(full_map, &map) == 1)
		return (free(full_map), NULL);
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
	return (0);
}

char	*ft_read_map(char *file_name)
{
	char	*next_line;
	char	*full_map;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_print_error("File not found check if you have the permissions");
		return (NULL);
	}
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
		if (next_line)
			full_map = ft_str_free_join_gnl(full_map, next_line);
	}
	free(next_line);
	return (close(fd), full_map);
}
