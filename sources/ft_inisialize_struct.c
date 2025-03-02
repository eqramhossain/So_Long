/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inisialize_struct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 10:27:41 by ehossain          #+#    #+#             */
/*   Updated: 2025/03/02 14:03:32 by ehossain         ###   ########.fr       */
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
