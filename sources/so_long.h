/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:26:25 by ehossain          #+#    #+#             */
/*   Updated: 2025/03/31 10:34:43 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"

# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100
# define ESC 65307

# define WALL '1'
# define FLOOR '0'
# define COLLECT 'C'
# define PLAYER 'P'
# define EXIT 'E'
# define EXIT_OPEN 'O'
# define EXIT_CLOSE_PLAYER 'S'

# define TILE_SIZE 64

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
	void		*door_close_player_img;
	void		*door_open_img;
}				t_img;

typedef struct s_map
{
	int			ac;
	int			fd;
	int			empty_spaces;
	int			walls;
	int			collects;
	int			c_check;
	int			exits;
	int			e_check;
	int			player;
	t_player	player_pos;
	int			other;
	int			row;
	int			column;
	int			move;
	char		*next_line;
	char		*tmp_map;
	char		*filename;
	char		**full_map;
	char		**copy_map;
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
}				t_map;

/* function that check if the map file and the map is valid */
void			ft_read_map(t_map *map);
void			ft_newline_check(char *map);
void			ft_is_map_rectangular(t_map *map);
void			ft_is_closed_top_bottom(t_map *map);
void			ft_is_closed_left_right(t_map *map);
void			ft_is_all_character_present(t_map *map);
void			ft_flood_fill_verif(t_map *map);

/* these functions help moving the character */
void			ft_move_up(t_map *map);
void			ft_move_down(t_map *map);
void			ft_move_left(t_map *map);
void			ft_move_right(t_map *map);

/* these functions help visualise the game using minilibx */
void			ft_xpm_to_image(t_map *map);
void			ft_print_elements_to_window(t_map *map);
void			ft_redraw_map(t_map *map);
void			ft_exit_open(t_map *map);

/* function that print error in stderr output*/
void			ft_error_exit(char *str);

/* function that destroy the image ptr */
void			ft_destroy_image(t_map *map);

/* functions handle the keypress and exit */
int				ft_on_keypress(int keycode, t_map *map);
int				ft_on_destroy(t_map *map);

/* these functions frees allocated memomy */
void			ft_freeup(char **str);
void			ft_free(t_map *map);
void			ft_free_exit(t_map *map);

/* YOU WON */
void			ft_win(t_map *map);

#endif
