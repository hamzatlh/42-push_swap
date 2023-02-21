/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:50:11 by htalhaou          #+#    #+#             */
/*   Updated: 2023/02/21 19:06:38 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int min_value(t_list *head)
{
    int min;
	int	value;
	
	min = INT_MAX;
    while (head)
    {
        value = head->content;
        if (value < min)
            min = value;
        head = head->next;
    }
    return (min);
}

int pos(t_list *stack, int value)
{
    int pos;

	pos = 0;
    while (stack != NULL)
    {
        pos++;
        if (stack->content == value)
            return (pos);
        stack = stack->next;
    }
    return (-1);
}

void sort_five(t_list **stack_a, t_list **stack_b, int size)
{
    int min;
    int i;
    int n;

    if (size == 5)
        n = 2;
    else if (size == 4)
        n = 1;
    i = 1;
    while (i <= n)
    {
        min = min_value(*stack_a);
        while ((*stack_a)->content != min)
        {
            if (pos(*stack_a, min) > ft_lstsize(*stack_a) / 2)
					reverse_rotate_a(stack_a);

            else
					rotate_a(stack_a);
        }
        push_b(stack_a, stack_b);
        i++;
    }
    ft_sort_3numbers(stack_a);
    push_a(stack_a, stack_b);
    push_a(stack_a, stack_b);
}
