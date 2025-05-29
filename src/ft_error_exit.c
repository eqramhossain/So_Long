/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 00:02:55 by ehossain          #+#    #+#             */
/*   Updated: 2025/05/29 16:48:14 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_exit(char *str)
{
	ft_putstr_fd("ERROR\n", 2);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}
