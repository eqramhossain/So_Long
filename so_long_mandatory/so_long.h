/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:26:25 by ehossain          #+#    #+#             */
/*   Updated: 2025/02/26 21:35:15 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"
// # include "../minilibx_mac/mlx.h"
# include "structure.h"
# include <errno.h>

/* function that check if the map file and the map is valid */
char	*ft_file_map_check(char *file_name);
int		ft_is_file_ok(char *file_name);
char	*ft_read_map(char *file_name);
int		ft_is_map_rectangular(char *full_map, t_line_length *line_length);
int		ft_is_map_closed(char *full_map);
int		ft_is_closed_top_bottom(char *full_map, int line, int line_len);
int		ft_is_closed_left_right(char *full_map, int line, int line_len);
int		ft_is_all_character_present(char *full_map, t_map *map);
int		ft_flood_fill(char *full_map);
int		ft_flood_fill_verif(char **map, t_position player_pos,
			t_position count);
/* function that print error in stderr and exit the program */
void	ft_print_error(char *str);

/* these functions initialize structures  */
void	ft_initialize_t_map(t_map *map);
void	ft_initialize_t_line_length(t_line_length *line_length);

/* these functions frees the passed parameter */
void	ft_freeup(char **str);
#endif
