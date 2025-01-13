/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackb_fns.c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:35:36 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/01/10 16:20:42 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_b(t_stacks *stack)
{
	int temp;
	int top;
	
	temp = 0;
	top = stack->top_b;
	temp = stack->stacka[top];
	stack->stacka[top] = stack->stacka[top - 1];
	stack->stacka[top - 1] = temp;
	ft_printf("sb\n");
}

void rotate_b(t_stacks *stack)
{
	int temp;
	int top;
	
	top = stack->top_b;
	temp = stack->stacka[top];
	ft_memmove(stack->stacka + 1,stack->stacka,  top * sizeof(int));
	stack->stacka[0] = temp;
	ft_printf("ra\n");
}