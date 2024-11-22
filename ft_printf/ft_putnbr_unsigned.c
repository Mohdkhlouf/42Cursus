/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:37:40 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/11/21 15:31:58 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsigned(unsigned long long n, int *count)
{
	if (n == 0)
	{
		ft_putchar('0', count);
	}
	else
	{
		if (n > 9)
		{
			ft_putnbr(n / 10, count);
			ft_putnbr(n % 10, count);
		}
		else
		{
			n = n + 48;
			ft_putchar(n, count);
		}
	}
}
