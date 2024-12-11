/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mklouf@student.hive.fi>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:24:20 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/08/13 17:16:23 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_sqrt(int nb)
{	
	int	number;

	number = 0;
	if (nb < 0)
		return (0);
	while (number * number < nb)
		number++;
	if (number * number == nb)
		return (number);
	return (0);
}
/*
int	main(void)
{
	printf("%d", ft_sqrt(-45));
	return (0);
}
*/
