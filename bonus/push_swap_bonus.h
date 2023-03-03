/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:37:17 by htalhaou          #+#    #+#             */
/*   Updated: 2023/03/03 17:55:00 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../li/libft.h"
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_sat
{
	int			end;
	int			start;
	int			j;
	int			size;
	int			i;
	t_list		*a;
	t_list		*b;
}t_sat;

// utils : 
void	split_and_join(char **av, char ***str);
int		sorted_numbers(char **arr);
int		is_sorted_arr(t_list *a);
int		empty(char *str);
int		max_value(t_list *head);
int		pos(t_list *stack, int value);
int		min_value(t_list *head);

// operations :
void	swap_a(t_list **head_a);
void	swap_b(t_list **head_b);
void	push_a(t_list **head_a, t_list **head_b);
void	push_b(t_list **head_a, t_list **head_b);
void	rotate_a(t_list **head_a);
void	rotate_b(t_list **head_b);
void	reverse_rotate_a(t_list **head_a);
void	reverse_rotate_b(t_list **head_b);
void	ss(t_list **head_a, t_list **head_b);
void	rr(t_list **head_a, t_list **head_b);
void	rrr(t_list **head_a, t_list **head_b);

// stack :
void	stack_to_array(t_list *stack_a, int *array, int size);
int		pop(t_list **top);;
int		peek(t_list **top);
void	push(t_list **top, int content);
void	next_instr(char *app);
void	more_func(t_sat fun, char *app);

#endif