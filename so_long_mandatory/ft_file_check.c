/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:16:48 by ehossain          #+#    #+#             */
/*   Updated: 2025/02/22 20:24:38 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_file_check(char *file_name)
{
	ft_null_format_check(file_name);
	return (0);
}

int	ft_null_format_check(char *file_name)
{
	int	len;
	int	fd;

	len = ft_strlen(file_name);
	fd = open(file_name, O_RDWR);
	if (fd == -1)
	{
		ft_print_error("File not found check if you have the permissions");
	}
	if (!ft_strnstr(file_name, ".ber", len))
	{
		ft_print_error("Incorrect file format expected file format example.ber");
	}
	if (get_next_line(fd) == NULL)
	{
		ft_print_error("File is empty");
	}
	return (0);
}
