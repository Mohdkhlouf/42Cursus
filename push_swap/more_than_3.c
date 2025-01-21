/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_than_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:51 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/01/21 02:35:09 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pass_radix_bitwise(t_stacks *stack, int div_base)
{
	int i;
	int bottom;

	i = 0;
	bottom = stack->bottom_a;
			while (i <= bottom)
			{				
				if((get_bit_digit_bitwise((stack->stacka[0]), div_base) & 1) == 0)
					push_b(stack);		
				else
					rotate_a(stack);
				i++;
			}
}


void radix_bitwise(t_stacks *stack)
{
	int i;

	i = 0;
	while (i < stack->digits_number_bitwise)
	{
		pass_radix_bitwise(stack, i);
		push_all_b(stack);
		i++;
	}
}
