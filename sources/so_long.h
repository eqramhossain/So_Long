/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:26:25 by ehossain          #+#    #+#             */
/*   Updated: 2025/03/04 23:59:47 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include "so_long_struct.h"

typedef struct t_player
{
	int			x;
	int			y;
}				t_player;

typedef struct s_map
{
	int			fd;
	int			empty_spaces;
	int			walls;
	int			collect;
	int			collect_check;
	int			exits;
	int			exit_check;
	int			player_check;
	t_player	player_pos;
	int			row;
	int			column;
	char		*line;
	char		*tmp_map;
	char		*filename;
	char		**full_map;
	char		**copy_map;
}				t_map;

/* function that check if the map file and the map is valid */
void			ft_inisialize_t_map(t_map *map);
void			ft_arguments_check(int ac, char **av);
void			ft_file_not_empty(char *file);
void			ft_read_map(char *file, t_map *map);

// void   ft_is_map_rectangular(void);
// void	ft_is_map_closed(void);
// void	ft_is_closed_top_bottom(void);
// void	ft_is_closed_left_right(void);
// void	ft_is_all_character_present(void);
// void	ft_flood_fill(char **map);
// void	ft_flood_fill_verif(char **map, t_player player_pos,
//		t_count count);

/* function that print error in stderr output*/
void			ft_error(char *str);
void			ft_error_exit(char *str);

/* these functions frees allocated memomy */
void			ft_freeup(char **str);

#endif
