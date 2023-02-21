/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:04:25 by htalhaou          #+#    #+#             */
/*   Updated: 2023/02/21 20:14:34 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int max_value(t_list *head)
{
    int max;
    int value;
	
    max = INT_MIN;
    while (head)
    {
        value = head->content;
        if (value > max)
            max = value;
        head = head->next;
    }
    return (max);
}

void    sort_arr(int *arr, int size)
{
    int    i;
    int    tmp;

    size++;
    while (--size)
    {
        i = 0;
        while (i < size - 1)
        {
            if (arr[i] > arr[i + 1])
            {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
            }
            i++;
        }
    }
}

void	sort_one_or_five_hundred(t_list	**stack_a, t_list **stack_b, int end , int *arr, int size)
{
    int start;
    int j;

    start = 0;
    while (*stack_a)
    {
        j = 0;
        while (j < size)
        {
            if ((*stack_a)->content == arr[j])
            {
                if (j >= start && j <= end)
                {
                    push_b(stack_a, stack_b);
                    start++;
                    end++;
                }
                else if (j < start)
                {
                    push_b(stack_a, stack_b);
                    rotate_b(stack_b);
                    start++;
                    end++;
                }
                else if (j > end)
                    rotate_a(stack_a);
                break;
            }
            j++;
        }
    }
}

void    sort_100_500(t_list **stack_a, t_list **stack_b, int size)
{
    int max;
    int i;

    i = 1;
    while (i <= size)
    {
        max = max_value(*stack_b);
        if ((*stack_b)->content != max)
        {
            if (pos(*stack_b, max) > ft_lstsize(*stack_b) / 2)
			{
                 while ((*stack_b)->content != max)
                     reverse_rotate_b(stack_b);
            }
            else
			{
                while ((*stack_b)->content != max)
                    rotate_b(stack_b);
            }
        }
        push_a(stack_a, stack_b);
        i++;
    }
}
