/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_map_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:26:18 by ehossain          #+#    #+#             */
/*   Updated: 2025/02/24 20:44:34 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_is_file_ok(char *file_name)
{
	int	len;
	int	fd;

	len = ft_strlen(file_name);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_print_error("File not found check if you have the permissions");
		close(fd);
	}
	if (!ft_strnstr(file_name, ".ber", len))
	{
		ft_print_error("Expected file format example.ber");
		close(fd);
	}
	if (get_next_line(fd) == NULL)
	{
		ft_print_error("File is empty");
		close(fd);
	}
	close(fd);
	return (0);
}

char	*ft_is_map_ok(char *file_name)
{
	char	*next_line;
	char	*full_map;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ft_print_error("File not found check if you have the permissions");
	next_line = ft_calloc(1, sizeof(char));
	if (!next_line)
		return (NULL);
	full_map = ft_calloc(1, sizeof(char));
	if (!next_line)
		return (NULL);
	while (next_line != NULL)
	{
		next_line = get_next_line(fd);
		if (next_line)
			full_map = ft_str_free_join(full_map, next_line);
	}
	free(next_line);
	fd = close(fd);
	ft_is_map_rectangular(full_map);
	return (full_map);
}
