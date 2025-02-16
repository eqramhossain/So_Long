/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:49:25 by ehossain          #+#    #+#             */
/*   Updated: 2025/02/13 11:11:32 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*currnet;
	t_list	*prev;

	currnet = malloc(1 * sizeof(t_list));
	prev = malloc(1 * sizeof(t_list));
	if (!prev || !currnet)
		return ;
	currnet = *lst;
	if (currnet == NULL)
		currnet = new;
	else if (currnet->next == NULL)
		currnet->next = new;
	else
	{
		while (currnet->next != NULL)
		{
			prev = currnet;
			currnet = currnet->next;
		}
	}
	currnet->next = new;
}
