/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:44:03 by ehossain          #+#    #+#             */
/*   Updated: 2025/02/24 09:29:43 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_str_free_join(char *str1, char *str2)
{
	char	*tmp_buffer;

	tmp_buffer = ft_strjoin(str1, str2);
	if (!tmp_buffer)
	{
		free(str1);
		str1 = NULL;
		return (NULL);
	}
	free(str1);
	str1 = NULL;
	return (tmp_buffer);
}
