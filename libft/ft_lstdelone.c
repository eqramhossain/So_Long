/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:03:43 by ehossain          #+#    #+#             */
/*   Updated: 2025/02/13 11:54:52 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	ft_print_list(t_list *head);
// void	ft_del(void *content);
//
// int	main(void)
// {
// 	t_list	*head;
// 	t_list	*lst1;
// 	t_list	*lst2;
//
// 	head = ft_calloc(1, sizeof(t_list));
// 	lst1 = ft_calloc(1, sizeof(t_list));
// 	lst2 = ft_calloc(1, sizeof(t_list));
// 	head->content = malloc(sizeof(int));
// 	*(int *)(head->content) = 42;
// 	lst1->content = malloc(sizeof(int));
// 	*(int *)(lst1->content) = 4242;
// 	lst2->content = malloc(sizeof(int));
// 	*(int *)(lst2->content) = 424242;
// 	head->next = lst1;
// 	lst1->next = lst2;
// 	lst2->next = NULL;
// 	ft_print_list(head);
// 	ft_lstdelone(lst1, ft_del);
// 	head->next = lst2;
// 	ft_print_list(head);
// 	return (0);
// }
//
// void	ft_print_list(t_list *head)
// {
// 	t_list	*position;
//
// 	position = head;
// 	while (position != NULL)
// 	{
// 		printf("value = %d\n", *(int *)position->content);
// 		position = position->next;
// 	}
// }
//
// void	ft_del(void *content)
// {
// 	free(content);
// }

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	(*del)(lst->content);
	free(lst);
	lst = NULL;
}
