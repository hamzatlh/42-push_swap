/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_utils_ab_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:48:10 by htalhaou          #+#    #+#             */
/*   Updated: 2023/03/02 19:38:40 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ss(t_list **head_a, t_list **head_b)
{
	swap_a(head_a);
	swap_b(head_b);
}

void	rr(t_list **head_a, t_list **head_b)
{
	rotate_a(head_a);
	rotate_b(head_b);
}

void	rrr(t_list **head_a, t_list **head_b)
{
	reverse_rotate_a(head_a);
	reverse_rotate_b(head_b);
}
