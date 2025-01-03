/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:25:21 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/01/03 17:26:09 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strcpy(char *dest, char *src)
{
	char	*orginal;

	orginal = dest;
	while (*src != 0)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (orginal);
}