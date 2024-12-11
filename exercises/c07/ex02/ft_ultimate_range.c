/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mklouf@student.hive.fi>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 11:41:42 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/08/19 18:39:54 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
//#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	min_counter;

	i = 0;
	min_counter = min;
	*range = malloc(sizeof (int) * (max - min));
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	if (*range == NULL)
		return (-1);
	while (min_counter < max)
	{
		(*range)[i] = min_counter;
		i++;
		min_counter++;
	}
	return (max - min);
}
/*
int	main(void)
{
	int	*arr;

	printf("%d", ft_ultimate_range(&arr, 5, 10));
	return (0);
}
*/
