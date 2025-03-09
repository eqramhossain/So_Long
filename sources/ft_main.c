/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:28:55 by ehossain          #+#    #+#             */
/*   Updated: 2025/03/09 12:26:38 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_inisialize_t_map(t_map *map, char **av, int ac);
static void	ft_map_init(t_map *map);

int	main(int ac, char *av[])
{
	t_map	map;
	t_img	img;

	ft_inisialize_t_map(&map, av, ac);
	ft_arguments_check(&map);
	ft_file_not_empty(map.filename);
	ft_map_init(&map);
	map.mlx_ptr = mlx_init();
	map.win_ptr = mlx_new_window(map.mlx_ptr, 1980, 1020, "so_long");
	ft_xpm_to_image(map.mlx_ptr, &img);
	mlx_put_image_to_window(map.mlx_ptr, map.win_ptr, img.door_close_img, 5, 5);
	mlx_loop(map.mlx_ptr);
	return (0);
}

static void	ft_inisialize_t_map(t_map *map, char **av, int ac)
{
	map->fd = 0;
	map->empty_spaces = 0;
	map->walls = 0;
	map->collects = 0;
	map->exits = 0;
	map->player = 0;
	map->player_pos.x = 0;
	map->player_pos.y = 0;
	map->row = 0;
	map->column = 0;
	map->filename = av[1];
	map->ac = ac;
	map->full_map = NULL;
	map->copy_map = NULL;
}

static void	ft_map_init(t_map *map)
{
	ft_read_map(map);
	ft_is_map_rectangular(map);
	ft_is_closed_top_bottom(map);
	ft_is_closed_left_right(map);
	ft_is_all_character_present(map);
	ft_flood_fill_verif(map);
}
