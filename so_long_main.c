/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:28:55 by ehossain          #+#    #+#             */
/*   Updated: 2025/02/17 12:34:28 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char *av[])
{
	char	*str;

	if (ac > 1)
	{
		ft_printf("av[i] = %d\n", av[1]);
		ft_printf("ft_strlen = %z\n", ft_strlen(av[1]);
		while (str) 
		{
			str = get_next_line(av[2]);
			ft_printf("str = %s", str);
		}
	}
	return (0);
}
