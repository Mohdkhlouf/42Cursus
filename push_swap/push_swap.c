/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:51 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/01/10 18:09:54 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort3(t_stacks *stack)
{
	if(stack->stacka[0] > stack->stacka[1] && stack->stacka[1] > stack->stacka[2])
		{
			swap_a(stack);
			rotate_a(stack);
			rotate_a(stack);
		}
	else if (stack->stacka[0] > stack->stacka[1] && stack->stacka[0] > stack->stacka[2]) 
		{
			rotate_a(stack);
			rotate_a(stack);
		}
	else if (stack->stacka[0] > stack->stacka[1] && stack->stacka[0] < stack->stacka[2])
		{
			swap_a(stack);
			rotate_a(stack);	
		}
	else if (stack->stacka[0] < stack->stacka[1] && stack->stacka[0] > stack->stacka[2])
		rotate_a(stack);
	else
		swap_a(stack);
	}

void push_swap(t_stacks *stacks)
{
	int j;

	j = 0;
	print_stack(stacks);
	if (stacks->counter == 3)
		sort3(stacks);
	print_stack(stacks);

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
