/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:56:22 by htalhaou          #+#    #+#             */
/*   Updated: 2023/03/03 17:57:09 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push(t_list **head, int content)
{
	t_list	*tmp;

	tmp = ft_lstnew(content);
	tmp->next = *head;
	*head = tmp;
}

int	pop(t_list **head)
{
	t_list	*tmp;
	int		result;

	if (*head == NULL)
		return (-1);
	tmp = *head;
	result = tmp->content;
	*head = tmp->next;
	free(tmp);
	return (result);
}

int	peek(t_list **head)
{
	if (*head == NULL)
		return (-1);
	return ((*head)->content);
}

void	stack_to_array(t_list *stack_a, int *array, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		array[i] = stack_a->content;
		stack_a = stack_a->next;
		i++;
	}
}
