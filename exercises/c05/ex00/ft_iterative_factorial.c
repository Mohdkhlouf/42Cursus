/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mklouf@student.hive.fi>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:32:38 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/08/12 16:35:45 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>
//#include <stdio.h>
int	ft_iterative_factorial(int nb)
{
	int	result;
	int	i;

	result = 1;
	i = 0;
	if (nb >= 0)
	{
		while (i < nb)
		{
			result = result * (nb - i);
			i++;
		}
		return (result);
	}
	else
		return (0);
}
/*
int	main(void)
{
	printf("%d",ft_iterative_factorial(0));
	return (0);
}
*/
