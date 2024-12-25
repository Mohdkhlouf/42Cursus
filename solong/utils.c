/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:29:16 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/12/25 16:10:38 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[count])
		count++;
	ptr = (char *)malloc(count +1);
	if (!ptr)
		return (NULL);
	while (i < count)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}