/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mklouf@student.hive.fi>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:38:36 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/08/14 11:24:59 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	if (power > 1)
		nb = nb * ft_recursive_power(nb, power - 1);
	return (nb);
}
/*
int main(void)
{
	printf("%d", ft_recursive_power(2147483647,5));	
	return (0);
}
*/
