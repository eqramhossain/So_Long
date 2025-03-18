/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:28:55 by ehossain          #+#    #+#             */
/*   Updated: 2025/03/17 15:40:05 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_inisialize_t_map(t_map *map, char **av, int ac);
static void	ft_map_init(t_map *map);

int	main(int ac, char *av[])
{
	t_map	map;

	ft_inisialize_t_map(&map, av, ac);
	ft_arguments_check(&map);
	ft_file_not_empty(map.filename);
	ft_map_init(&map);
	map.mlx_ptr = mlx_init();
	map.win_ptr = mlx_new_window(map.mlx_ptr, map.column * 64, map.row * 64,
			"so_long");
	ft_xpm_to_image(&map);
	ft_print_elements_to_window(&map);
	mlx_hook(map.win_ptr, 17, 1L << 17, ft_on_destroy, &map);
	mlx_hook(map.win_ptr, 02, 1L << 0, ft_on_keypress, &map);
	mlx_loop(map.mlx_ptr);
	return (0);
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

static void	ft_inisialize_t_map(t_map *map, char **av, int ac)
{
	map->fd = 0;
	map->empty_spaces = 0;
	map->walls = 0;
	map->collects = 0;
	map->c_check = 0;
	map->exits = 0;
	map->e_check = 0;
	map->player = 0;
	map->player_pos.x = 0;
	map->player_pos.y = 0;
	map->other = 0;
	map->row = 0;
	map->column = 0;
	map->move = 0;
	map->filename = av[1];
	map->ac = ac;
	map->full_map = NULL;
	map->copy_map = NULL;
}
