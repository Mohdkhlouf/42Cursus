/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:37:40 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/11/19 14:28:40 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsigned(unsigned int n, int *count)
{
	if (n < 0)
	{
		ft_putnbr_unsigned((4294967295 - n), count);
		(*count)++;
	}
	else if (n == 0)
	{
		write(1, "0", 1);
		(*count)++;
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
			write(1, &n, 1);
			(*count)++;
		}
	}
}
