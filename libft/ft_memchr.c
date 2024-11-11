/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:17:24 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/11/07 11:45:36 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((char *)s)[i] == (char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
// int main(void)
// {

// 	char str[]="mohammad";
// 	char * result = ft_memchr(str, 'd', 8);
// 	printf("%s", result);
// 	return (0);
// }