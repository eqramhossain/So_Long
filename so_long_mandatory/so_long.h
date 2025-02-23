/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:26:25 by ehossain          #+#    #+#             */
/*   Updated: 2025/02/23 14:27:01 by ehossain         ###   ########.fr       */
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

int		ft_file_check(char *file_name);
char	*ft_map_check(char *file_name);
void	ft_print_error(char *str);

#endif
