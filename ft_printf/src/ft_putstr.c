/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:46:17 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/19 18:43:55 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int *count)
{
	int	i;

	i = 0;
	if(!s)
	{
		// write(1,"(null)",6);
		// (*count) = (*count) + 6;
		ft_putstr("(null)", count);
	}
	else
	{
		while (s[i])
		{
			ft_putchar(s[i], count);
			i++;
		}
	}
	
}
