/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_3numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:24:27 by htalhaou          #+#    #+#             */
/*   Updated: 2023/02/25 17:17:49 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3numbers(t_list **head_a)
{
	int	a;
	int	b;
	int	c;

	a = (*head_a)->content;
	b = (*head_a)->next->content;
	c = (*head_a)->next->next->content;
	if (a < c && b < a)
		swap_a(head_a);
	else if (a > b && b > c)
	{
		swap_a(head_a);
		reverse_rotate_a(head_a);
	}
	else if (a > c && c > b)
		rotate_a(head_a);
	else if (c > a && b > c)
	{
		swap_a(head_a);
		rotate_a(head_a);
	}
	else if (a > c && b > a)
		reverse_rotate_a(head_a);
}
