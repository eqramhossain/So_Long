/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:28:55 by ehossain          #+#    #+#             */
/*   Updated: 2025/02/25 21:29:02 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char *av[])
{
	char	*full_map;
	char	**map;

	if (ac != 2)
		return (ft_print_error("File not found!"), 0);
	full_map = ft_file_map_check(av[1]);
	if (full_map == NULL)
		return (free(full_map), 1);
	map = ft_split(full_map, '\n');
	if (!map)
	{
		ft_freeup(map);
		free(full_map);
		return (0);
	}
	free(full_map);
	ft_freeup(map);
	return (0);
}

void	ft_freeup(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
