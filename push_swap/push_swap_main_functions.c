/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:51 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/01/23 18:48:41 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	inner_check(t_stacks *stack)
{
	if (stack->stacka[1] > stack->stacka[2])
	{
		swap_a(stack);
		reverse_rotate_a(stack);
	}
	else
		rotate_a(stack);
}

void	sort3(t_stacks *stack)
{
	if (stack->stacka[0] < stack->stacka[1]
		&& stack->stacka[1] < stack->stacka[2])
		return ;
	else
	{
		if (stack->stacka[0] > stack->stacka[1]
			&& stack->stacka[0] > stack->stacka[2])
			inner_check(stack);
		else if (stack->stacka[0] > stack->stacka[1]
			&& stack->stacka[0] < stack->stacka[2])
			swap_a(stack);
		else if (stack->stacka[0] < stack->stacka[1]
			&& stack->stacka[0] > stack->stacka[2])
			reverse_rotate_a(stack);
		else
		{
			swap_a(stack);
			rotate_a(stack);
		}
	}
}
