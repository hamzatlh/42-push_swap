/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:56:22 by htalhaou          #+#    #+#             */
/*   Updated: 2023/03/07 19:36:26 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	stack_to_array(t_list *stack_a, int *array, int size)
{
	int		i;
	int		content;
	t_list	**tmp;

	i = 0;
	tmp = &stack_a;
	while (i < size)
	{
		array[i] = (*tmp)->content;
		(*tmp) = (*tmp)->next;
		i++;
	}
}
