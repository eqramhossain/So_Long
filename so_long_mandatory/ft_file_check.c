/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:16:48 by ehossain          #+#    #+#             */
/*   Updated: 2025/02/23 14:28:47 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_file_check(char *file_name)
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
		ft_print_error("Incorrect file format expected file format example.ber");
	}
	if (get_next_line(fd) == NULL)
	{
		ft_print_error("File is empty");
	}
	close(fd);
	return (0);
}

char	*ft_map_check(char *file_name)
{
	char	*next_line;
	char	*full_map;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ft_print_error("File not found check if you have the permissions");
	next_line = ft_calloc(1, sizeof(char));
	full_map = ft_calloc(1, sizeof(char));
	while (next_line != NULL)
	{
		next_line = get_next_line(fd);
		if (next_line)
			full_map = ft_str_free_join(full_map, next_line);
	}
	free(next_line);
	ft_printf("%s", full_map);
	fd = close(fd);
	return (full_map);
}
