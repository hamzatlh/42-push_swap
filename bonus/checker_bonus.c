/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:07:50 by htalhaou          #+#    #+#             */
/*   Updated: 2023/03/02 21:44:07 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	instr(t_list *a, t_list *b, char *app)
{
	if (strcmp(app, "rb") == 0)
		rotate_b(&b);
	else if (strcmp(app, "ra") == 0)
		rotate_a(&a);
	else if (strcmp(app, "sa") == 0)
		swap_a(&a);
	else if (strcmp(app, "sb") == 0)
		swap_b(&b);
	else if (strcmp(app, "rra") == 0)
		reverse_rotate_a(&a);
	else if (strcmp(app, "rrb") == 0)
		reverse_rotate_b(&b);
	else if (strcmp(app, "pa") == 0)
		push_a(&a, &b);
	else if (strcmp(app, "pb") == 0)
		push_b(&a, &b);
	else if (strcmp(app, "rr") == 0)
		rr(&a, &b);
	else if (strcmp(app, "ss") == 0)
		ss(&a, &b);
	else if (strcmp(app, "rrr") == 0)
		rrr(&a, &b);
	else
	{
		ft_putstr_fd("Error\n", 2);
		exit (0);
	}
}

int	main(int ac, char **av)
{
	t_sat		fun;
	char		**str;
	static char	*app;
	int			*arr;

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
	arr = malloc(ft_lstsize(fun.a) * sizeof(int));
	stack_to_array(fun.a, arr, ft_lstsize(fun.a));
	fun.size = ft_lstsize(fun.b);
	while (1)
	{
		app = get_next_line(0);
		instr(fun.a, fun.b, app);
		if (is_sorted_arr(arr, ft_lstsize(fun.a)) && fun.size == 0)
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
	}
	return (0);
}
