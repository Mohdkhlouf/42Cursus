/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mklouf@student.hive.fi>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:55:02 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/08/12 17:17:02 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>
//#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	result;

	i = 1;
	result = 1;
	if (power >= 0)
	{
		if (nb == 0 && power == 0)
			return (1);
		while (i <= power)
		{
			result = result * nb;
			i++;
		}
		return (result);
	}
	else
		return (0);
}
/*
int main(void)
{
	printf("%d", ft_iterative_power(1 , -5));
		   return (0);
}
*/
