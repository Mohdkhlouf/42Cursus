/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacka_funs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:37:55 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/01/15 21:15:58 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_a(t_stacks *stack)
{
	int temp;

	temp = 0;
	temp = stack->stacka[0];
	stack->stacka[0] = stack->stacka[1];
	stack->stacka[1] = temp;
	ft_printf("sa\n");
}

void rotate_a(t_stacks *stack)
{
	int temp;
	int top;
	
	top = stack->counter-1;
	temp = stack->stacka[0];
	ft_memmove(stack->stacka,stack->stacka + 1,  top * sizeof(int));
	stack->stacka[top] = temp;
	ft_printf("ra\n");
}

void reverse_rotate_a(t_stacks *stack)
{
	int temp;
	int top;
	
	top = stack->bottom_a;
	temp = stack->stacka[top];
	ft_memmove(stack->stacka + 1,stack->stacka,  top * sizeof(int));
	stack->stacka[0] = temp;
	ft_printf("rra\n");
}

void push_b(t_stacks *stack)
{
	if (stack->bottom_a == 0)
	{
		stack->stackb[++stack->bottom_b] = stack->stacka[stack->bottom_a];
	}
	else
	{
		stack->stackb[++stack->bottom_b] = stack->stacka[stack->bottom_a];
		ft_memmove(stack->stacka, stack->stacka,  ((stack->bottom_a - 1) * sizeof(int)));
	}
	stack->bottom_a -= 1;
	ft_printf("pb\n");
}