/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:26:25 by ehossain          #+#    #+#             */
/*   Updated: 2025/03/02 15:04:09 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include "so_long_struct.h"
# include <errno.h>
# define GREEN "\033[0;32m"
# define RED "\033[1;31m"
# define GREY "\033[0;90m"
# define CYAN "\033[1;96m"
# define RESET "\033[0m"

# define IMG_HEIGHT 32
# define IMG_WIDTH 32

# define WALL_XPM "assets/sprites/wall.xpm"
# define FLOOR_XPM "assets/sprites/floor.xpm"
# define COINS_XPM "assets/sprites/coin-bag.xpm"
# define PLAYER_FRONT_XPM "assets/sprites/player/front.xpm"
# define PLAYER_LEFT_XPM "assets/sprites/player/left.xpm"
# define PLAYER_RIGHT_XPM "assets/sprites/player/right.xpm"
# define PLAYER_BACK_XPM "assets/sprites/player/back.xpm"
# define OPEN_EXIT_XPM "assets/sprites/open-exit.xpm"
# define EXIT_CLOSED_XPM "assets/sprites/exit-closed.xpm"

/* function that check if the map file and the map is valid */
void	ft_arguments_check(t_map *map);
int		ft_is_file_ok(t_map *map);
int		ft_read_map(t_map *map);
int		ft_is_map_rectangular(char **map);
int		ft_is_map_closed(char **full_map);
int		ft_is_closed_top_bottom(char **full_map, t_count *tab);
int		ft_is_closed_left_right(char **full_map, t_count *tab);
int		ft_is_all_character_present(t_map *map);
int		ft_flood_fill(char **map);
int		ft_flood_fill_verif(char **map, t_position player_pos, t_count count);
char	**ft_strstrcpy(t_map *map);
void	ft_inisialize_t_map(t_map *map);
void	ft_validpath_check(char **new_map, char **old_map);

/* function that print error in stderr output*/
void	ft_error(char *str);

/* these functions frees allocated memomy */
void	ft_freeup(char **str);

#endif

// # define WALL				'1'
// # define FLOOR 				'0'
// # define COINS  			'C'
// # define PLAYER				'P'
// # define MAP_EXIT 				'E'
//
// # define KEY_W				119
// # define KEY_A				97
// # define KEY_S				115
// # define KEY_D				100
//
// # define KEY_UP  			65362
// # define KEY_LEFT  			65361
// # define KEY_RIGHT 			65363
// # define KEY_DOWN  			65364
//
// # define KEY_Q				113
// # define KEY_ESC  			65307
//
// # define FRONT				1
// # define LEFT				2
// # define RIGHT				3
// # define BACK				4
