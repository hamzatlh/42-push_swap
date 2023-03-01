/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:07:50 by htalhaou          #+#    #+#             */
/*   Updated: 2023/03/01 16:47:30 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_list *a, t_list *b, int size, int *arr)
{
	char	**str;

	if (size == 2)
		swap_a(&a);
	else if (size == 3)
		ft_sort_3numbers(&a);
	else if (size == 5 || size == 4)
		sort_five(&a, &b, size);
	else if (sorted_numbers_in_reverse(str))
	{
		sort_one_or_five_hundred(&a, &b, size, arr);
		sort_100_500(&a, &b, size);
	}
	else if (size > 5 && size <= 100)
	{
		sort_one_or_five_hundred(&a, &b, 15, arr);
		sort_100_500(&a, &b, size);
	}
	else
	{
		sort_one_or_five_hundred(&a, &b, 40, arr);
		sort_100_500(&a, &b, size);
	}
}

int	main(int ac, char **av)
{
	t_sat	fun;
	char	**str;
	int		*arr;

	fun.i = 0;
	if (ac < 1)
		exit(1);
	split_and_join(av, &str);
	while (str[fun.i])
		fun.i++;
	if (sorted_numbers(str))
		return (0);
	fun.i--;
	while (fun.i >= 0)
	{
		ft_lstadd_front(&fun.a, ft_lstnew(ft_atoi(str[fun.i])));
		fun.i--;
	}
	fun.size = ft_lstsize(fun.a);
	arr = malloc(fun.size * sizeof(int));
	stack_to_array(fun.a, arr, fun.size);
	sort_arr(arr, fun.size);
	sorting(fun.a, fun.b, fun.size, arr);
	return (0);
}
