/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:28:55 by ehossain          #+#    #+#             */
/*   Updated: 2025/02/19 17:23:54 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(int ac, char *av[])
{
	t_data	image;
	void	*mlx;
	void	*new_window;
	int		i;
	int		j;

	i = 500;
	j = 500;
	(void)ac;
	(void)av;
	mlx = mlx_init();
	new_window = mlx_new_window(mlx, 1920, 1080, "so_long");
	(void)new_window;
	image.img = mlx_new_image(mlx, 1920, 1080);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
			&image.line_length, &image.endian);
	while (i < 1000)
	{
		j = 0;
		while (j < 1000)
		{
			my_mlx_pixel_put(&image, i, j, 0x00FF0000);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx, new_window, image.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}

// if (ac != 2)
// {
// 	ft_printf("please provide a file\n");
// 	return (0);
// }
// if (!ft_fd_check(av[1]))
// {
// 	ft_printf("incorrect file format expected file format example.ber\n");
// 	return (0);
// }
