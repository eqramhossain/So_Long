/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newline_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:55:01 by ehossain          #+#    #+#             */
/*   Updated: 2025/03/06 15:54:58 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_newline_check(char *map)
{
	int	i;

	i = 0;
	if (map[0] == '\n')
	{
		free(map);
		ft_error_exit("There is a newline at start of the file.");
	}
	else
	{
		while (map[i])
		{
			if (map[i] == '\n' && map[i + 1] == '\n')
			{
				free(map);
				ft_error_exit("There is a newline in the file.");
			}
			i++;
		}
	}
}
