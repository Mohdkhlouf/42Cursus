/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:26:26 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/11/19 14:28:36 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *count)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*count) = (*count) + 11;
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		(*count)++;
		n = n * -1;
		ft_putnbr(n, count);
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
			write(1, &(char){n + '0'}, 1);
			(*count)++;
		}
	}
}
