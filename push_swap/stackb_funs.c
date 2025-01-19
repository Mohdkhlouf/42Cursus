/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackb_funs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:35:36 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/01/18 21:15:37 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_b(t_stacks *stack)
{
	int temp;
	int top;
	
	temp = 0;
	top = stack->bottom_b;
	temp = stack->stacka[top];
	stack->stacka[top] = stack->stacka[top - 1];
	stack->stacka[top - 1] = temp;
	ft_printf("sb\n");
}

void rotate_b(t_stacks *stack)
{
	int temp;
	int top;
	
	top = stack->bottom_b;
	temp = stack->stacka[top];
	ft_memmove(stack->stacka + 1,stack->stacka,  top * sizeof(int));
	stack->stacka[0] = temp;
	ft_printf("ra\n");
}

void reverse_rotate_b(t_stacks *stack)
{
	int temp;
	int top;
	
	top = stack->bottom_b;
	temp = stack->stackb[top];
	ft_memmove(stack->stackb + 1,stack->stackb,  top * sizeof(int));
	stack->stackb[0] = temp;
	ft_printf("rrb\n");
}

void push_a(t_stacks *stack)
{
	if (stack->bottom_b == 0)
	{	
		ft_memmove(stack->stacka + 1, stack->stacka,  ((stack->bottom_a + 1) * sizeof(int)));
		stack->stacka[0] = stack->stackb[0];
		stack->bottom_a++;
	}
	else if(stack->bottom_b > 0)
	{
		ft_memmove(stack->stacka + 1, stack->stacka,  ((stack->bottom_a +1) * sizeof(int)));
		stack->stacka[0] = stack->stackb[0];
		ft_memmove(stack->stackb, stack->stackb + 1,  ((stack->bottom_b) * sizeof(int)));
		stack->bottom_a++;	
	}
	stack->bottom_b -= 1;
	ft_printf("pa\n");
}