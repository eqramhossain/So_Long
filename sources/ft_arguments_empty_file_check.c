/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arguments_empty_file_check.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:01:48 by ehossain          #+#    #+#             */
/*   Updated: 2025/03/03 14:29:01 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_arguments_check(int ac, char **av)
{
	int	len_file_name;

	if (ac == 1)
		ft_error_exit("Please provide a file");
	else if (ac > 2)
		ft_error_exit("Multiple files");
	len_file_name = ft_strlen(av[1]);
	if (!ft_strnstr(av[1], ".ber", len_file_name))
		ft_error_exit("Worng file format (expected file format example.ber)");
}

void	ft_file_not_empty(char *file)
{
	int		fd;
	char	*next_line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error_exit("File not found. Does the file even exists!");
	next_line = get_next_line(fd);
	if (!next_line)
		ft_error_exit("File is empty");
	while (next_line)
	{
		free(next_line);
		next_line = get_next_line(fd);
	}
	close(fd);
}
