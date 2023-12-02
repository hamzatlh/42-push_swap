/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:03:28 by htalhaou          #+#    #+#             */
/*   Updated: 2023/03/07 21:28:10 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned int nb, int upper, int *count)

{
	char	*base;

	if (upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nb < 16)
	{
		ft_putchar(base[nb], count);
	}
	else
	{	
		ft_putnbr_base(nb / 16, upper, count);
		ft_putnbr_base(nb % 16, upper, count);
	}
}
