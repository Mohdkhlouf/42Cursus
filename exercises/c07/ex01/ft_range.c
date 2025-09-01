/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mklouf@student.hive.fi>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:20:40 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/08/19 18:15:55 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
//#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	len;
	int	*arr;
	int	i;

	i = 0;
	len = max - min;
	arr = (int *)malloc(sizeof(int) * len);
	if (min >= max)
		return (NULL);
	while (min < max)
	{
		arr[i] = min;
		i++;
		min++;
	}
	return (arr);
}
/*
int	main(void)
{	
	int	i;
	int	*into;
	
	i=0;
	into = ft_range(2, 10);
	return (0);
}
*/
