/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:04:25 by htalhaou          #+#    #+#             */
/*   Updated: 2023/02/20 22:03:19 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_max(t_list *head)
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
    int    t;

    size++;
    while (--size)
    {
        i = 0;
        while (i < size - 1)
        {
            if (arr[i] > arr[i + 1])
            {
                t = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = t;
            }
            i++;
        }
    }
}

void	sort_one_hundred(t_list	**stack_a, t_list **stack_b, int end , int *arr, int size)
{
    int start;
    // int end;
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

void sort_100(t_list **stack_a, t_list **stack_b, int size)
{
    int max;
    int i;

    i = 1;
    while (i < 500 && *stack_b)
    {
        max = find_max(*stack_b);
        if ((*stack_b)->content != max)
        {
            if (get_position(*stack_b, max) > ft_lstsize(*stack_b) / 2)
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
    push_a(stack_a, stack_b);
}

// void sort_one_hundred(t_list *stack_a, t_list *stack_b, int *arr, int size)
// {
//     int start = 0;
//     int end = size / 6 - 1;
//     int j;
//     while (stack_a)
//     {
//         j = 0;
//         while (j < size)
//         {
//             if ((stack_a)->content == arr[j])
//             {
//                 if (j >= start && j <= end)
//                 {
//                     if (stack_a)
//                         push_b(&stack_a, &stack_b);
//                     start++;
//                     end++;
//                 }
//                 else if (j < start)
//                 {
//                     if (stack_a)
//                         push_b(&stack_a, &stack_b);
//                     if (stack_b)
//                         rotate_b(&stack_b);
//                     start++;
//                     end++;
//                 }
//                 else if (j > end)
//                 {
//                     if (stack_a)
//                         rotate_a(&stack_a);
//                     end = j;
//                 }
//                 break;
//             }
//             j++;
//         }
//     }
// }
