/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:16:48 by ehossain          #+#    #+#             */
/*   Updated: 2025/02/20 15:49:51 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_fd_check(char *name)
{
	int	len;

	len = ft_strlen(name);
	if (ft_strnstr(name, ".ber", len))
	{
		return (1);
	}
	return (0);
}
