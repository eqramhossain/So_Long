/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:26:25 by ehossain          #+#    #+#             */
/*   Updated: 2025/03/07 15:42:47 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"

typedef struct s_row_column
{
	int			row;
	int			column;
}				t_row_column;

typedef struct s_player
{
	int			x;
	int			y;
}				t_player;

typedef struct s_img
{
}				t_img;

typedef struct s_map
{
	int			ac;
	int			fd;
	int			empty_spaces;
	int			walls;
	int			collects;
	int			exits;
	int			player;
	t_player	player_pos;
	int			row;
	int			column;
	char		*next_line;
	char		*tmp_map;
	char		*filename;
	char		**full_map;
	char		**copy_map;
	void		*mlx_ptr;
	void		*mlx_window;
}				t_map;

/* function that check if the map file and the map is valid */
void			ft_inisialize_t_map(t_map *map, char **av, int ac);
void			ft_arguments_check(t_map *map);
void			ft_file_not_empty(char *file);
void			ft_map_init(t_map *map);
void			ft_read_map(t_map *map);
void			ft_newline_check(char *map);
void			ft_is_map_rectangular(t_map *map);
void			ft_is_closed_top_bottom(t_map *map);
void			ft_is_closed_left_right(t_map *map);
void			ft_is_all_character_present(t_map *map);
void			ft_flood_fill_verif(t_map *map);

/* function that print error in stderr output*/
void			ft_error_exit(char *str);

/* these functions frees allocated memomy */
void			ft_freeup(char **str);
void			ft_free_exit(t_map *map);

#endif
