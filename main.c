/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:07:50 by htalhaou          #+#    #+#             */
/*   Updated: 2023/02/20 22:10:09 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_list *a;
	t_list *b;
	int		size;
	char	**str;
	int		i;
	int		*arr;

	i= 0;
	if (ac < 1)
		exit(1);
	split_and_join(av, &str);
	while (str[i])
		i++;
	if(is_ascending_order(str))
		return (0);
	i--;
	while (i >= 0)
	{
		ft_lstadd_front(&a, ft_lstnew(ft_atoi(str[i])));
		i--;
	}
	int j;
	size = ft_lstsize(a);
	// ft_printf("the size of the stack is : %d\n", size);
	arr = malloc(size * sizeof(int));
	fill_array_from_stack(a, arr, size);
	sort_arr(arr, size);
	// print_stacks(a, b);
	if (size == 2)
		sort_two_numbers(&a);
	else if (size == 3)
		ft_sort_3numbers(&a);
	else if (size == 5 || size == 4)
		sort_five(&a, &b, size);
	else if (is_descending_order(str))
	{
		sort_one_hundred(&a, &b, size, arr, size);
	}
	else if (size > 5 && size <= 100)
	{
		sort_one_hundred(&a, &b, 15, arr, size);
		sort_100(&a, &b, size);
	}
	else
	{
		sort_one_hundred(&a, &b, 40, arr, size);
		sort_100(&a, &b, size);
	}
	// print_stacks(a, b);
	return (0);
}