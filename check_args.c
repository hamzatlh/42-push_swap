/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:14:05 by htalhaou          #+#    #+#             */
/*   Updated: 2023/03/07 21:36:16 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted_numbers(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] && arr[i + 1])
	{
		if (ft_atoi(arr[i]) < ft_atoi(arr[i + 1]))
			i++;
		else
			return (0);
	}
	return (1);
}

int	sorted_numbers_in_reverse(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] && arr[i + 1])
	{
		if (ft_atoi(arr[i]) > ft_atoi(arr[i + 1]))
			i++;
		else
			return (0);
	}
	return (1);
}

int	empty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] != ' ' && str[i] != '\t') && str[i] != '\0')
			return (1);
		i++;
	}
	return (0);
}

void	exit_prog(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free (str[i++]);
	free(str);
}
