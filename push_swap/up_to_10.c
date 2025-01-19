/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_to_10.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:51 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/01/19 04:02:26 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void pass_radix_10(t_stacks *stack, int div_base)
{
	int j;
	int i;
	int bottom;
	int position;

	j = 0;
	i = 0;
	position = 0;
	bottom = stack->bottom_a;
	while (j <= 9 && stack->bottom_a != -1 )
	{
		if(have_values(stack->stacka, bottom ,j, div_base))
		{
			i = 0;
			bottom = stack->bottom_a;
			while (i <= bottom)
			{

				if(get_bit_digit((stack->stacka[0]), div_base) == j)
					push_b(stack);			
				else
				{
					position = value_position(stack->stacka, stack->bottom_a,j, div_base);
					if (position == -1)
						break;
					if(position <= stack->bottom_a / 2)
						rotate_a(stack);
					else if (position > stack->bottom_a / 2)
						reverse_rotate_a(stack);
				} 

					if (stack->bottom_a == 2)
					{
						j = 9;
						break;
					}
				
				i++;
			}
		}
		j++;
	}

}


void up_to_10(t_stacks *stack)
{
	// print_stack(stack);
	pass_radix_10(stack, 0);
	sort3(stack);
	push_all_b(stack);
}