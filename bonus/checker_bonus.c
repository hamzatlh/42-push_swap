/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:07:50 by htalhaou          #+#    #+#             */
/*   Updated: 2023/03/14 15:33:03 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	instr(t_list **a, t_list **b, char *app, char **str)
{
	if (strcmp(app, "rb\n") == 0)
		rotate_b(b);
	else if (strcmp(app, "ra\n") == 0)
		rotate_a(a);
	else if (strcmp(app, "sa\n") == 0)
		swap_a(a);
	else if (strcmp(app, "sb\n") == 0)
		swap_b(b);
	else if (strcmp(app, "rra\n") == 0)
		reverse_rotate_a(a);
	else if (strcmp(app, "rrb\n") == 0)
		reverse_rotate_b(b);
	else if (strcmp(app, "pa\n") == 0)
		push_a(a, b);
	else if (strcmp(app, "pb\n") == 0)
		push_b(a, b);
	else if (strcmp(app, "rr\n") == 0)
		rr(a, b);
	else if (strcmp(app, "ss\n") == 0)
		ss(a, b);
	else if (strcmp(app, "rrr\n") == 0)
		rrr(a, b);
	else
		next_instr(a, b, app, str);
}

void	next_instr(t_list **a, t_list **b, char *app, char **str)
{
	ft_putstr_fd("Error\n", 2);
	free (app);
	exit_prog(str);
	ft_lstclear(a, &del);
	ft_lstclear(b, &del);
	exit (1);
}

void	more_func(t_sat fun, char *app, char **str)
{
	while (1)
	{
		app = get_next_line(0);
		if (app)
		{
			instr(&fun.a, &fun.b, app, str);
			free (app);
		}
		else
			break ;
	}
	if (fun.a && is_sorted_arr(fun.a) && !fun.b)
	{
		ft_putstr_fd("OK\n", 1);
		ft_lstclear(&fun.a, &del);
		ft_lstclear(&fun.b, &del);
	}	
	else
	{
		ft_putstr_fd("KO\n", 1);
		ft_lstclear(&fun.a, &del);
		ft_lstclear(&fun.b, &del);
	}
}

int	main(int ac, char **av)
{
	t_sat		fun;
	char		**str;
	char		*app;
	int			*arr;

	init(&fun);
	if (ac == 1)
		exit(1);
	split_and_join(av, &str);
	while (str[fun.i])
		fun.i++;
	fun.i--;
	while (fun.i >= 0)
	{
		ft_lstadd_front(&fun.a, ft_lstnew(ft_atoi(str[fun.i])));
		fun.i--;
	}
	more_func(fun, app, str);
	exit_prog(str);
	return (0);
}
