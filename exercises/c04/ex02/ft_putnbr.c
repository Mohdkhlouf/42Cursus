/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mklouf@student.hive.fi>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 20:49:40 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/08/12 12:56:30 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print_str(char *c, int i)
{
	while (i >= 0)
	{
		write(1, &c[i], 1);
		i--;
	}
}

void	ft_putnbr(int nb)
{
	int		i;
	char	c[10];

	i = 0;
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nb < 0)
	{
		nb = nb * -1;
		write (1, "-", 1);
	}
	while (nb > 0)
	{
		c[i++] = (nb % 10) + 48;
		nb = nb / 10;
	}
	print_str(c, i - 1);
}
/*
int	main(void)
{
	ft_putnbr(21474836);
	return (0);
}
*/
