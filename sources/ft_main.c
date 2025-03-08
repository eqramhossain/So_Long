/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:28:55 by ehossain          #+#    #+#             */
/*   Updated: 2025/03/08 12:52:41 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_inisialize_t_map(t_map *map, char **av, int ac);

int	main(int ac, char *av[])
{
	t_map	map;
	int		a;
	int		b;

	a = 5;
	b = 5;
	ft_inisialize_t_map(&map, av, ac);
	ft_arguments_check(&map);
	ft_file_not_empty(map.filename);
	ft_map_init(&map);
	map.mlx_ptr = mlx_init();
	map.mlx_window = mlx_new_window(map.mlx_ptr, map.column * IMG_SIZE, map.row
			* IMG_SIZE, WIN_NAME);
	map.img.wall = mlx_xpm_file_to_image(map.mlx_ptr, WALL, &a, &b);
	mlx_put_image_to_window(map.mlx_ptr, map.mlx_window, map.img.wall, map.row
		- 3, map.column - 5);
	mlx_loop(map.mlx_ptr);
	return (0);
}

// for (int i = 0; map.full_map[i]; i++)
// 	printf("%s\n", map.full_map[i]);
// for (int j = 0; map.copy_map[j]; j++)
// 	printf("%s\n", map.copy_map[j]);

void	ft_inisialize_t_map(t_map *map, char **av, int ac)
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

void	ft_map_init(t_map *map)
{
	ft_read_map(map);
	ft_is_map_rectangular(map);
	ft_is_closed_top_bottom(map);
	ft_is_closed_left_right(map);
	ft_is_all_character_present(map);
	ft_flood_fill_verif(map);
}
