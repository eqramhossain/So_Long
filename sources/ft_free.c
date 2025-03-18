/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 19:31:36 by ehossain          #+#    #+#             */
/*   Updated: 2025/03/17 10:18:13 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_freeup(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
}

void	ft_free_exit(t_map *map)
{
	if (map->next_line)
		free(map->next_line);
	if (map->tmp_map)
		free(map->tmp_map);
	if (map->full_map)
		free(map->full_map);
	if (map->copy_map)
		free(map->copy_map);
	exit(EXIT_FAILURE);
}

void	ft_free(t_map *map)
{
	if (map->next_line)
		free(map->next_line);
	if (map->tmp_map)
		free(map->tmp_map);
	if (map->full_map)
		free(map->full_map);
	if (map->copy_map)
		free(map->copy_map);
	if (map->mlx_ptr)
		free(map->mlx_ptr);
}
