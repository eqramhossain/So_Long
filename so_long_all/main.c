/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:28:55 by ehossain          #+#    #+#             */
/*   Updated: 2025/02/19 10:10:06 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	void	*mlx_connection;
	void	*mlx_window;
	int		i;
	int		x;
	int		j;

	i = 0;
	x = 0;
	j = 0;
	mlx_connection = mlx_init();
	mlx_window = mlx_new_window(mlx_connection, 1000, 1000, "so_long");
	while (i < 1000)
	{
		j = 0;
		while (j < 1000)
		{
			x = mlx_pixel_put(mlx_connection, mlx_window, i, j, 0x0000FF);
			j++;
		}
		i++;
	}
	ft_printf("%d\n", x);
	mlx_loop(mlx_connection);
	return (0);
}
