/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mklouf@student.hive.fi>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:15:53 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/08/13 17:15:54 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	i;
	int	result;

	if (nb < 2)
		return (2);
	i = nb;
	while (i)
	{
		result = ft_is_prime(i);
		if (result == 1)
			return (i);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	printf("%d\n", ft_find_next_prime(4));
	printf("%d\n", ft_find_next_prime(-112));
	printf("%d\n", ft_find_next_prime(3001));
	printf("%d\n", ft_find_next_prime(5001));
	return (0);
}
*/
