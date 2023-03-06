/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:07:50 by htalhaou          #+#    #+#             */
/*   Updated: 2023/03/06 21:56:56 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_sat *fun, int *arr, char **str)
{
	if (fun->size == 2)
		swap_a(&fun->a);
	else if (fun->size == 3)
		ft_sort_3numbers(&fun->a);
	else if (fun->size == 5 || fun->size == 4)
		sort_five(&fun->a, &fun->b, fun->size);
	else if (sorted_numbers_in_reverse(str))
	{
		sort_one_or_five_hundred(&fun->a, &fun->b, fun->size, arr);
		sort_100_500(&fun->a, &fun->b, fun->size);
	}
	else if (fun->size > 5 && fun->size <= 100)
	{
		sort_one_or_five_hundred(&fun->a, &fun->b, 15, arr);
		sort_100_500(&fun->a, &fun->b, fun->size);
	}
	else
	{
		sort_one_or_five_hundred(&fun->a, &fun->b, 40, arr);
		sort_100_500(&fun->a, &fun->b, fun->size);
	}
	free (arr);
}

void	del(int i)
{
	(void)i;
}

void	init(t_sat *fun)
{
	fun->i = 0;
	fun->a = 0;
	fun->b = 0;
}

void	next_oper(t_sat fun, int *arr, char **str)
{
	stack_to_array(fun.a, arr, fun.size);
	sort_arr(arr, fun.size);
	sorting(&fun, arr, str);
	exit_prog(str);
	ft_lstclear(&fun.a, &del);
}

int	main(int ac, char **av)
{
	t_sat	fun;
	char	**str;
	int		*arr;

	init(&fun);
	if (ac < 1)
		exit(1);
	split_and_join(av, &str);
	while (str[fun.i])
		fun.i++;
	if (sorted_numbers(str))
	{
		exit_prog(str);
		return (0);
	}
	fun.i--;
	while (fun.i >= 0)
	{
		ft_lstadd_front(&fun.a, ft_lstnew(ft_atoi(str[fun.i])));
		fun.i--;
	}
	fun.size = ft_lstsize(fun.a);
	arr = malloc(fun.size * sizeof(int));
	next_oper(fun, arr, str);
	return (0);
}
