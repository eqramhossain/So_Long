/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:34:01 by ehossain          #+#    #+#             */
/*   Updated: 2025/03/22 12:40:19 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_win(t_map *map)
{
	ft_destroy_image(map);
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	mlx_destroy_display(map->mlx_ptr);
	ft_freeup(map->full_map);
	ft_freeup(map->copy_map);
	ft_free(map);
	ft_printf("YOU WON");
	exit(EXIT_SUCCESS);
	return ;
}
