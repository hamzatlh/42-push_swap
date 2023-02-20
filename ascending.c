/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascending.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:14:05 by htalhaou          #+#    #+#             */
/*   Updated: 2023/02/20 22:16:27 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_ascending_order(char **arr)
{
    int i;
    
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

int is_descending_order(char **arr)
{
    int i;
    
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

int empty(char *str)
{
    int i;

    i = 0;
    while (str[i])
	{
        if ((str[i] != ' ' && str[i] != '\t') && str[i] != '\0')
            return (1);
        i++;
    }
    return (0);
}
