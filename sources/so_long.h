/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:26:25 by ehossain          #+#    #+#             */
/*   Updated: 2025/03/09 12:08:27 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"

# define WALL "images/so_long_ekram/WALL.xpm"
# define EMPTY "images/so_long_ekram/empty.xpm"
# define COLLECT "images/so_long_ekram/collect.xpm"
# define MAIN "images/so_long_ekram/main.xpm"
# define DOOR_OPEN "images/so_long_ekram/test.xpm"
# define DOOR_CLOSE "images/so_long_ekram/test1.xpm"

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
	void		*wall_img;
	void		*empty_img;
	void		*collect_img;
	void		*main_img;
	void		*door_close_img;
	void		*door_open_img;
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
	void		*win_ptr;
}				t_map;

/* function that check if the map file and the map is valid */
void			ft_arguments_check(t_map *map);
void			ft_file_not_empty(char *file);
void			ft_read_map(t_map *map);
void			ft_newline_check(char *map);
void			ft_is_map_rectangular(t_map *map);
void			ft_is_closed_top_bottom(t_map *map);
void			ft_is_closed_left_right(t_map *map);
void			ft_is_all_character_present(t_map *map);
void			ft_flood_fill_verif(t_map *map);

/* these functions help visualise the game using minilibx */
void			ft_xpm_to_image(void *mlx_ptr, t_img *img);

/* function that print error in stderr output*/
void			ft_error_exit(char *str);

/* these functions frees allocated memomy */
void			ft_freeup(char **str);
void			ft_free_exit(t_map *map);

#endif
