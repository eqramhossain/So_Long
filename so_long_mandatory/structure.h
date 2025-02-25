/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:29:37 by ehossain          #+#    #+#             */
/*   Updated: 2025/02/25 21:55:33 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_map
{
	int		i;
	int		empty_space;
	int		wall;
	int		collectible;
	int		exit;
	int		player;
}			t_map;

typedef struct s_line_length
{
	int		i;
	int		current;
	int		first;

}			t_line_length;
#endif
