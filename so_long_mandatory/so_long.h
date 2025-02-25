/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:26:25 by ehossain          #+#    #+#             */
/*   Updated: 2025/02/25 17:01:01 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "../minilibx_mac/mlx.h"
# include "structure.h"
# include <errno.h>

# define EXIT_FAILURE 1
/* function that check if the map file and the map is valid */
int		ft_file_map_check(char *file_name);
int		ft_is_file_ok(char *file_name);
char	*ft_read_map(char *file_name);
int		ft_is_map_rectangular(char *full_map);
int		ft_is_map_closed(char *full_map);
int		ft_is_closed_top_bottom(char *full_map, int line, int line_len);
int		ft_is_closed_left_right(char *full_map, int line, int line_len);
int		ft_is_all_character_present(char *full_map, t_map *map);

/* function that print error in stderr and exit the program */
void	ft_print_error(char *str);

/* these functions initialize structures  */
void	ft_initialize_t_map(t_map *map);
#endif
