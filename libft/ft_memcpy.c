/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:17:43 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/11/08 15:01:00 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	while (i < n)
	{
		((char *)s1)[i] = ((char *)s2)[i];
		i++;
	}
	return (s1);
}
// int main(void)
// {
// 	char str[]="Hello, World! 123456";
// 	char str2[] = "Ali";
// 	size_t n= 3;
// 	printf("Before: %s\n", str);
// 	ft_memcpy(str+7,str,10);
// 	printf("After: %s", str);
// 	return (0);
// }