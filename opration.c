/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opration.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 23:08:53 by htalhaou          #+#    #+#             */
/*   Updated: 2023/03/07 20:56:48 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **head_a)
{
	t_list	*tmp;

	if (*head_a == NULL || (*head_a)->next == NULL)
		return ;
	tmp = *head_a;
	*head_a = (*head_a)->next;
	tmp->next = (*head_a)->next;
	(*head_a)->next = tmp;
	ft_printf("sa\n");
}

void	swap_b(t_list **head_b)
{
	t_list	*tmp;

	if (*head_b == NULL || (*head_b)->next == NULL)
		return ;
	tmp = *head_b;
	*head_b = (*head_b)->next;
	tmp->next = (*head_b)->next;
	(*head_b)->next = tmp;
	ft_printf("sb\n");
}

void	push_a(t_list **head_a, t_list **head_b)
{
	t_list	*temp;

	if (*head_b == NULL)
		return ;
	temp = *head_b;
	*head_b = (*head_b)->next;
	temp->next = *head_a;
	*head_a = temp;
	ft_printf("pa\n");
}

void	push_b(t_list **head_a, t_list **head_b)
{
	t_list	*temp;

	if (*head_a == NULL)
		return ;
	temp = *head_a;
	*head_a = (*head_a)->next;
	temp->next = *head_b;
	*head_b = temp;
	ft_printf("pb\n");
}
