/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 23:47:58 by htalhaou          #+#    #+#             */
/*   Updated: 2023/03/09 18:12:53 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rotate_a(t_list **head_a)
{
	t_list	*temp;
	int		v;

	temp = NULL;
	if (*head_a == NULL || (*head_a)->next == NULL)
		return ;
	v = pop(head_a);
	while (*head_a)
		ft_lstadd_front(&temp, ft_lstnew(pop(head_a)));
	ft_lstadd_front(head_a, ft_lstnew(v));
	while (temp)
		ft_lstadd_front(head_a, ft_lstnew(pop(&temp)));
}

void	rotate_b(t_list **head_b)
{
	t_list	*temp;
	int		v;

	temp = NULL;
	if (*head_b == NULL || (*head_b)->next == NULL)
		return ;
	v = pop(head_b);
	while (*head_b)
		ft_lstadd_front(&temp, ft_lstnew(pop(head_b)));
	ft_lstadd_front(head_b, ft_lstnew(v));
	while (temp)
		ft_lstadd_front(head_b, ft_lstnew(pop(&temp)));
}

void	reverse_rotate_a(t_list **head_a)
{
	t_list	*temp;
	t_list	*pos;

	if (*head_a == NULL || (*head_a)->next == NULL)
		return ;
	pos = *head_a;
	while (pos->next->next != NULL)
		pos = pos->next;
	temp = pos->next;
	pos->next = NULL;
	temp->next = *head_a;
	*head_a = temp;
}

void	reverse_rotate_b(t_list **head_b)
{
	t_list	*temp;
	t_list	*pos;

	if (*head_b == NULL || (*head_b)->next == NULL)
		return ;
	pos = *head_b;
	while (pos->next->next != NULL)
		pos = pos->next;
	temp = pos->next;
	pos->next = NULL;
	temp->next = *head_b;
	*head_b = temp;
}
