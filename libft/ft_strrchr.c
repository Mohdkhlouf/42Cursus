/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:18:59 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/11/07 18:28:15 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char )c)
			return ((char *) &s[i]);
		i--;
	}
	return (NULL);
}
// int main(void)
// {
// 	char s[]="mohaad";
// 	int c = 'm';

// 	char *result = ft_strrchr(s,c);
// 	printf("%s\n",result);
// 	printf("%ld\n",result-s);
// 	return (0);
// }