/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:33:20 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/11/21 15:31:50 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *count)
{
	ssize_t	result;

	result = write(1, &c, 1);
	if (result == -1)
	{
		(*count) = -1;
		return ;
	}
	(*count)++;
}
