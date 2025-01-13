/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:51 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/01/13 11:54:27 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void how_many_digits(t_stacks *stack)
{
	int digits;

	digits = 0;
	if (stack->max_int == 0)
		digits = 1;
	while (stack->max_int != 0)
		{
			stack->max_int = stack->max_int / 10;
			digits++;
		}
	stack->digits_number = digits;
	ft_printf("how many digits  %d\n", digits);
}

void max_number_digits(t_stacks *stack)
{
	int i;
	int max;
	
	i = 0;
	max = 0;
	while (i < stack->counter)
	{
		if (stack->stacka[i] < 0)
			stack->stacka[i]*= -1;
		if (stack->stacka[i]> max)
			max = stack->stacka[i];
		i++;
	}
	stack->max_int = max;
	ft_printf("Max digits number %d\n", max);
	how_many_digits(stack);
}

int base(int n)
{
	int result;
	
	result = 1;
	while (n >= 0)
	{
		result = result * 10;
		n--;
	}
	return (result);
}
void big_stack(t_stacks *stack)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	max_number_digits(stack);
	while (j <= stack->digits_number)
	{
		while ( i < stack->counter)
		{ 
			if(stack->stacka[i] % base(j) == j)
				ft_printf("number is %d\n", stack->stacka[i]);
			i++;
		}
		j++;
	}
}

void sort3(t_stacks *stack)
{
	if (stack->stacka[0] > stack->stacka[1] && stack->stacka[0] > stack->stacka[2]) 
		{
			if (stack->stacka[1] > stack->stacka[2])
				swap_a(stack);
			rotate_a(stack);
		}
	else if (stack->stacka[0] > stack->stacka[1] && stack->stacka[0] < stack->stacka[2])
		{
			swap_a(stack);
			reverse_rotate_a(stack);	
		}
	else if (stack->stacka[0] < stack->stacka[1] && stack->stacka[0] > stack->stacka[2])
		reverse_rotate_a(stack);
	else
		swap_a(stack);
}


void push_swap(t_stacks *stacks)
{
	int j;

	j = 0;
	if (stacks->counter == 3)
		sort3(stacks);
	if (stacks->counter > 3)
		big_stack(stacks);
}

int main(int argc, char *argv[])
{
	t_stacks stacks;
	int i;
	int j;

	i = 0;
	j = 0;
	stacks.counter = 0;
	check_arguments(argc, argv, &stacks);
	check_duplicated(&stacks);
	if(check_sorted(&stacks))
		print_free_exit(&stacks, "Sorted");
	else
		push_swap(&stacks);
	free(stacks.stacka);	
	return (0);
}
