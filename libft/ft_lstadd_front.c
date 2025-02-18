/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:31:32 by ehossain          #+#    #+#             */
/*   Updated: 2025/02/13 11:11:18 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*tmp_node;

	tmp_node = malloc(1 * sizeof(t_list));
	if (!tmp_node)
		return ;
	tmp_node = *lst;
	*lst = new;
	new->next = tmp_node;
}
