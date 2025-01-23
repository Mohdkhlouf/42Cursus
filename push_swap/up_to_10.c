/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_to_10.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:25:21 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/01/23 17:35:12 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_5(int bottom, t_stacks *stack, int div_base, int *j)
{
	int	i;

	i = 0;
	while (i <= bottom)
	{
		if (get_bit_digit((stack->stacka[0]), div_base) == *j)
			push_b(stack);
		else
		{
			stack->position = value_position(stack->stacka, stack->bottom_a, *j,
					div_base);
			if (stack->position == -1)
				break ;
			if (stack->position <= stack->bottom_a / 2)
				rotate_a(stack);
			else if (stack->position > stack->bottom_a / 2)
				reverse_rotate_a(stack);
		}
		if (stack->bottom_a == 2)
		{
			*j = 9;
			break ;
		}
		i++;
	}
}

void	pass_radix_5(t_stacks *stack, int div_base)
{
	int	j;
	int	bottom;

	j = 0;
	bottom = stack->bottom_a;
	while (j <= 9 && stack->bottom_a != -1)
	{
		if (have_values(stack->stacka, bottom, j, div_base))
		{
			bottom = stack->bottom_a;
			radix_5(bottom, stack, div_base, &j);
		}
		j++;
	}
}

void	up_to_10(t_stacks *stack)
{
	pass_radix_5(stack, 0);
	if (stack->sorted == 1)
	{
		if (stack->bottom_b != -1)
			push_all_b(stack);
	}
	else
	{
		sort3(stack);
		push_all_b(stack);
	}
}
