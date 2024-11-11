/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:17:57 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/11/08 13:33:36 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int x, size_t n)
{
	size_t	i;
	char	*str2;

	str2 = ptr;
	i = 0;
	while (i < n)
	{
		str2[i] = x;
		i++;
	}
	return (ptr);
}
/*
int main(void)
{
	char str[]="Mohammad Khlouf";
	printf("Before:%s\n", str);
	ft_memset(str ,'.' , 30 * sizeof(char));
	printf("After:%s", str);
	return (0);
}
*/