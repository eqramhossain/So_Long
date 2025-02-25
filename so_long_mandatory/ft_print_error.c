/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 19:31:36 by ehossain          #+#    #+#             */
/*   Updated: 2025/02/25 18:01:23 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_error(char *str)
{
	if (!str)
		return ;
	ft_putstr_fd("\e[31mERROR: \e[0m\n", 2);
	ft_putstr_fd("\e[31m", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\e[0m\n", 2);
}
