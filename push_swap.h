/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:46:35 by htalhaou          #+#    #+#             */
/*   Updated: 2023/02/20 21:49:05 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "li/libft.h"
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

void	split_and_join(char **av, char ***str);
int		is_ascending_order(char **arr);
int		empty(char *str);
void    print_stacks(t_list *s1, t_list *s2);
int		find_max(t_list *head);
int		get_position(t_list *stack, int value);

// operations :
void 	swap_a(t_list **head_a);
void 	swap_b(t_list **head_b);
void 	push_a(t_list **head_a, t_list **head_b);
void 	push_b(t_list **head_a, t_list **head_b);
void 	rotate_a(t_list **head_a);
void 	rotate_b(t_list **head_b);
void 	reverse_rotate_a(t_list **head_a);
void 	reverse_rotate_b(t_list **head_b);
void	ss(t_list **head_a, t_list **head_b);
void 	rr(t_list **head_a, t_list **head_b);
void 	rrr(t_list **head_a, t_list **head_b);

// sorting :
void	ft_sort_3numbers(t_list **head_a);
void	sort_two_numbers(t_list **head);
void	sort_five(t_list **stack_a, t_list **stack_b, int size);
void	sort_one_hundred(t_list	**stack_a, t_list **stack_b, int end , int *arr, int size);
void	sort_100(t_list **stack_a, t_list **stack_b, int size);

// stack :
int		peek(t_list **top);
void	push(t_list **top, int content);
int		pop(t_list **top);
void	fill_array_from_stack(t_list *stack_a, int *array, int size);
void	sort_arr(int *arr, int size);

int is_descending_order(char **arr);
#endif