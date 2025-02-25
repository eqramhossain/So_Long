/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:28:55 by ehossain          #+#    #+#             */
/*   Updated: 2025/02/25 17:23:22 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char *av[])
{
	char	*full_map;

	if (ac != 2)
	{
		ft_print_error("File not found!");
		return (0);
	}
	full_map = ft_file_map_check(av[1]);
	if (!full_map)
		return (ft_print_error("NULL MAP"), 1);
	free(full_map);
	return (0);
}
