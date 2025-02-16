/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:52:21 by ehossain          #+#    #+#             */
/*   Updated: 2025/02/13 12:41:00 by ehossain         ###   ########.fr       */
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
// 	ft_lstclear(&head, ft_del);
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
//
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		ft_lstdelone(current, del);
		current = next;
	}
	*lst = NULL;
}
