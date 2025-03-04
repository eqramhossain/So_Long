/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:28:55 by ehossain          #+#    #+#             */
/*   Updated: 2025/03/03 15:29:01 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_inisialize_t_map(t_map *map)
{
	map->walls = 0;
	map->empty_spaces = 0;
	map->exits = 0;
	map->players = 0;
	map->collects = 0;
}

int	main(int ac, char *av[])
{
	t_map	map;

	ft_arguments_check(ac, av);
	ft_file_not_empty(av[1]);
	ft_read_map(av[1], &map);
	return (0);
}
