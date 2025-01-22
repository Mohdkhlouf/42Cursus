/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:51 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/01/22 18:45:06 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	how_many_digits(t_stacks *stack)
{
	int	digits;

	digits = 0;
	if (stack->max_int == 0)
		digits = 1;
	while (stack->max_int != 0)
	{
		stack->max_int = stack->max_int / 10;
		digits++;
	}
	stack->digits_number = digits;
}

void	max_number_digits(t_stacks *stack)
{
	int	i;
	int	max;
	int	*new_stack;
	int	bits;

	i = 0;
	max = 0;
	new_stack = malloc(sizeof(int) * stack->counter);
	if (!new_stack)
		print_free_exit(stack);
	ft_memcpy(new_stack, stack->stacka, stack->counter);
	while (i < stack->counter)
	{
		if (new_stack[i] > max)
			max = new_stack[i];
		i++;
	}
	stack->max_int = max;
	bits = 0;
	while (max >> bits != 0)
		bits++;
	stack->digits_number_bitwise = bits;
	free(new_stack);
	how_many_digits(stack);
}

int	have_values_in(int *stack, int top, int j, int div_base)
{
	int	i;
	int	have_value;

	i = top;
	have_value = 0;
	while (i >= 0)
	{
		if (get_bit_digit((stack[i]), div_base) == j)
		{
			have_value = 1;
			break ;
		}
		i--;
	}
	return (have_value);
}

int	have_values(int *stack, int top, int j, int div_base)
{
	int	i;
	int	have_value;

	i = 0;
	have_value = 0;
	while (i <= top)
	{
		if (get_bit_digit(stack[i], div_base) == j)
		{
			have_value = 1;
			break ;
		}
		i++;
	}
	return (have_value);
}

int	value_position(int *stack, int top, int j, int div_base)
{
	int	i;

	i = 0;
	while (i <= top)
	{
		if (get_bit_digit(stack[i], div_base) == j)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}
