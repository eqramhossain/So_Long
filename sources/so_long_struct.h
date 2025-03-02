/* ************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:29:37 by ehossain          #+#    #+#             */
/*   Updated: 2025/03/02 10:28:16 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_STRUCT_H
# define SO_LONG_STRUCT_H

typedef struct s_count
{
	int			i;
	int			j;
}				t_count;

typedef struct s_position
{
	int			x;
	int			y;
}				t_position;

typedef struct s_map
{
	int			fd;
	int			ac;
	int			len_file_name;
	int			empty_spaces;
	int			walls;
	int			collects;
	int			exits;
	int			players;
	char		*file_name;
	char		*next_line;
	char		*tmp_map;
	char		**av;
	char		**full_map;
	char		**copy_map;
	t_position	player_pos;
	t_count		tab;
}				t_map;

#endif
