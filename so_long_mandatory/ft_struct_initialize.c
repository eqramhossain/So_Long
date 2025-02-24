/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_initialize.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:14:52 by ehossain          #+#    #+#             */
/*   Updated: 2025/02/24 17:21:12 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_initialize_t_map(t_map *map)
{
	map->i = 0;
	map->empty_space = 0;
	map->wall = 0;
	map->collectible = 0;
	map->exit = 0;
	map->player = 0;
}
