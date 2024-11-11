/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:17:50 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/11/08 16:14:53 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*s;
	char	*d;

	i = 0;
	s = (char *)src;
	d = (char *)dest;
	if (!s && !d)
		return (NULL);
	if (d > s)
		while (n-- > 0)
			d[n] = s[n];
	else
		while (i++ < n)
			d[i - 1] = s[i - 1];
	return (d);
}
// int main(void)
// {
// 	char src[]="lorem ipsum dolor sit amet";
// 	char	*dest;
// 	dest = src + 1;
// 	int size = 128 * 1024 * 1024;
// 	char *dst = (char *)malloc(sizeof(char) * size);
// 	char *data = (char *)malloc(sizeof(char) * size);
// 	ft_memset(data, 'A', size);
// 	char  *result;
// 	result = ft_memmove(dst, data, size);
// 	printf("%s", result);
// 	return (0);
// }