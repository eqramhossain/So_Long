/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 19:31:36 by ehossain          #+#    #+#             */
/*   Updated: 2025/02/24 10:38:30 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_error(char *str)
{
	if (!str)
		return ;
	ft_putstr_fd("ERROR:\n", 2);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}
