/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:04:25 by htalhaou          #+#    #+#             */
/*   Updated: 2023/03/11 21:00:03 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_value(t_list *head)
{
	int	max;
	int	value;

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

void	sort_arr(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	sort_one_or_five_hundred(t_list	**stack_a, t_list **stack_b,
	int end, int *arr)
{
	t_sat	pos;
	int		size;

	pos.start = 0;
	pos.end = end;
	size = ft_lstsize(*(stack_a));
	while (*stack_a)
	{
		pos.j = 0;
		while (pos.j < size)
		{
			if ((*stack_a)->content == arr[pos.j])
			{
				sort_main_function(stack_a, stack_b, arr, &pos);
				break ;
			}
			pos.j++;
		}
	}
}

void	sort_main_function(t_list **stack_a, t_list **stack_b,
					int *arr, t_sat *pos)
{
	if (pos->j >= pos->start && pos->j <= pos->end)
	{
		push_b(stack_a, stack_b);
		pos->start += 1;
		pos->end += 1;
	}
	else if (pos->j < pos->start)
	{
		push_b(stack_a, stack_b);
		rotate_b(stack_b);
		pos->start += 1;
		pos->end += 1;
	}
	else if (pos->j > pos->end)
		rotate_a(stack_a);
}

void	sort_100_500(t_list **stack_a, t_list **stack_b, int size)
{
	int	max;
	int	i;

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
