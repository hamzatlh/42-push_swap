/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:46:11 by htalhaou          #+#    #+#             */
/*   Updated: 2023/03/07 21:54:36 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_int(char **arr)
{
	int		i;
	int		j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		if ((arr[i][j] == '-' && arr[i][j + 1] == '\0')
			|| (arr[i][j] == '+' && arr[i][j + 1] == '\0'))
		{
			ft_putstr_fd("Error\n", 2);
			exit_prog(arr);
			exit(1);
		}
		if (arr[i][j] == '-' || arr[i][j] == '+')
			j++;
		while (arr[i][j])
		{
			if (!(arr[i][j] >= '0' && arr[i][j] <= '9'))
				return (0);
			j++;
		}
	i++;
	}
	return (1);
}

int	check_duplicate(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
	j = i + 1;
		while (arr[j])
		{
			if (ft_atoi(arr[j]) == ft_atoi(arr[i]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_range(char **arr)
{
	int		i;
	long	tmp;

	i = 0;
	while (arr[i])
	{
	tmp = ft_atoi(arr[i]);
		if (tmp < INT_MIN || tmp > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

void	check_argument(char **arr)
{
	if (!check_int(arr) || check_duplicate(arr) || !check_range(arr))
	{
		ft_putstr_fd("Error\n", 2);
		exit_prog(arr);
		exit(1);
	}
}

void	split_and_join(char **av, char ***str)
{
	int		i;
	char	*joined_str;

	joined_str = NULL;
	i = 1;
	while (av[i])
	{
		if (!empty(av[i]))
		{
			ft_putstr_fd("Error\n", 2);
			free (joined_str);
			exit(1);
		}
		joined_str = ft_strjoin_gnl(joined_str, av[i]);
		joined_str = ft_strjoin_gnl(joined_str, " ");
		i++;
	}
	*str = ft_split(joined_str, ' ');
	free (joined_str);
	check_argument(*str);
}
