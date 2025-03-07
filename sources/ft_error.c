/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 00:02:55 by ehossain          #+#    #+#             */
/*   Updated: 2025/03/06 14:25:19 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_exit(char *str)
{
	ft_putstr_fd("\e[31m❌ERROR❌:\n", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\e[0m\n", 2);
	exit(EXIT_FAILURE);
}
