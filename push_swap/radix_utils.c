/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:51 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/01/21 14:10:08 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void set_positions(t_stacks *stack)
{
	int i;
	int j;

	i = 0;
	j = 0;
	stack->orginal = malloc(stack->counter * sizeof (int));
	ft_memcpy(stack->orginal, stack->stacka, stack->counter);
	while (i < stack->counter)
	{
		j = 0;
		while (j < stack->counter)
		{
			if (stack->stacka[i] == stack->sorted_stack[j])
			{
				stack->stacka[i] = j;
				break;
			}
			j++;
		}
	i++;
	}
}

void sort_array(t_stacks *stack)
{
    int i;
	int j;

	i = 0;
	j = 0;
	stack->sorted_stack = malloc(stack->counter * sizeof (int));
	ft_memcpy(stack->sorted_stack, stack->stacka, stack->counter);
    while (i < stack->counter)
	{
        j = i + 1;
        while (j < stack->counter)
		{
            if (stack->sorted_stack[i] > stack->sorted_stack[j])
			{
                int temp = stack->sorted_stack[i];
                stack->sorted_stack[i] = stack->sorted_stack[j];
                stack->sorted_stack[j] = temp;
            }
            j++;
        }
        i++;
    }
}


void push_all_b(t_stacks *stack)
{
	int i;

	i = stack->bottom_b;
	while (i >= 0)
	{
		push_a(stack);
		i--;
	}
}

void rotate_all_a(t_stacks *stack)
{
	int i;

	i = stack->bottom_a;
	while (i >= 0)
	{
		rotate_a(stack);
		i--;
	}
}

int get_bit_digit_bitwise(int n, int dive_base)
{
    return (n >> dive_base) & 1;
}
