/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:34:17 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/11/19 14:41:57 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_letters(uint64_t n, int *count)
{
	if (n == 10)
		ft_putchar('a', count);
	else if (n == 11)
		ft_putchar('b', count);
	else if (n == 12)
		ft_putchar('c', count);
	else if (n == 13)
		ft_putchar('d', count);
	else if (n == 14)
		ft_putchar('e', count);
	else if (n == 15)
		ft_putchar('f', count);
}

static void	ft_putptr_hex(uint64_t n, int *count)
{
	if (n > 15)
	{
		ft_putptr_hex(n / 16, count);
		ft_putptr_hex(n % 16, count);
	}
	else
	{
		if (n < 10)
			ft_putnbr(n, count);
		else
			print_letters(n, count);
	}
}

void	ft_putptr(void *n, int *count)
{
	uint64_t ptr;
	ptr = (uint64_t)n;
	if (!n)
		ft_putstr("(nil)", count);
	else
	{
		ft_putchar('0', count);
		ft_putchar('x', count);
		ft_putptr_hex(ptr, count);
	}
}