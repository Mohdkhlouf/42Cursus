/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacka_funs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:37:55 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/01/13 08:25:39 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_a(t_stacks *stack)
{
	int temp;
	int top;
	
	temp = 0;
	top = stack->counter - 1;
	temp = stack->stacka[top];
	stack->stacka[top] = stack->stacka[top - 1];
	stack->stacka[top - 1] = temp;
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
	
	top = stack->counter-1;
	temp = stack->stacka[top];
	ft_memmove(stack->stacka + 1,stack->stacka,  top * sizeof(int));
	stack->stacka[0] = temp;
	ft_printf("rra\n");
}