/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:48:36 by ehossain          #+#    #+#             */
/*   Updated: 2025/02/13 15:11:03 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*currnet;

	if (lst == NULL)
		return (NULL);
	else if (lst->next == NULL)
		return (lst);
	else
	{
		currnet = lst;
		while (currnet->next != NULL)
		{
			currnet = currnet->next;
		}
	}
	return (currnet);
}
