/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:51 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/01/19 04:15:50 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void pass_radix_a(t_stacks *stack, int div_base)
{
	int j;
	int i;
	int bottom;
	int position;

	j = 0;
	i = 0;
	position = 0;
	bottom = stack->bottom_a;
	while (j <= 9 && stack->bottom_a != -1)
	{
		if(have_values(stack->stacka, bottom ,j, div_base))
		{
			i = 0;
			bottom = stack->bottom_a;
			
			while (i <= bottom)
			{
				
				// printf("digit %d and j is %dand i is %d, base is %d \n",
				// 	get_bit_digit((stack->stacka[0]), div_base),j, i, div_base);
				if(get_bit_digit((stack->stacka[0]), div_base) == j)
					push_b(stack);			
				else
				{
					position = value_position(stack->stacka, stack->bottom_a,j, div_base);
					// if (position == -1)
					// {
					// 	// printf("possition is without value\n");
					// 	continue;
					// }
					if(position <= stack->bottom_a / 2)
					{
						// printf("possition is %d, smaller than middle of bottom %d\n", position, bottom);
						rotate_a(stack);
					}
					else if (position > stack->bottom_a / 2)
					{
						// printf("possition is %d, Bigger than middle of bottom %d\n", position, bottom);
					// printf("position is:%d from %d\n", position, bottom);
						reverse_rotate_a(stack);
					}
					
				}
				if (div_base == stack->digits_number - 1)
				{
					if(stack->bottom_a == 9)
						{
							j = 9;
							break;
						}
				}
				i++;

			}
		
		}
		j++;
	}
	
	// printf("%d", div_base);
	// print_stack(stack);
}

void sort3(t_stacks *stack)
{
	int i;

	i  = 0;
	if(stack->bottom_a != 2)
	{
		printf("Error");
		exit(-1);
	}
	if (stack->stacka[0] < stack->stacka[1] && stack->stacka[1] < stack->stacka[2])
		{
			i = i + 1;
			// you have to do something else;
		}
	else if (stack->stacka[0] > stack->stacka[1] && stack->stacka[0] > stack->stacka[2]) 
		{
			if (stack->stacka[1] > stack->stacka[2])
			{
				swap_a(stack);
				reverse_rotate_a(stack);
			}
			else
				rotate_a(stack);
		}
	else if (stack->stacka[0] > stack->stacka[1] && stack->stacka[0] < stack->stacka[2])
		{
			swap_a(stack);	
		}
	else if (stack->stacka[0] < stack->stacka[1] && stack->stacka[0] > stack->stacka[2])
		reverse_rotate_a(stack);
	else
	{
		swap_a(stack);
		rotate_a(stack);
	}
}

void big_stack(t_stacks *stack)
{
	int i;

	i = 0;

	// print_stack(stack);
	while (i < stack->digits_number)
	{
		pass_radix_a(stack, i);
		if(i == stack->digits_number - 1)
		 	up_to_10(stack);
		push_all_b(stack);
		i++;
	}
	// print_stack(stack);

	// rotate_all_a(stack);
	
}

void bigger_than_3(t_stacks *stacks)
{
	sort_array(stacks);
	set_positions(stacks);
	max_number_digits(stacks);

	if (stacks->counter <= 10)
		up_to_10(stacks);
	else if (stacks->counter > 10)
		big_stack(stacks);
}

void push_swap(t_stacks *stacks)
{
	stacks->stackb = malloc (stacks->counter * sizeof(int));
	if (!stacks->stackb)
		print_free_exit(stacks);
	stacks->bottom_a = stacks->counter - 1;
	if (stacks->counter == 3)
		sort3(stacks);
	if (stacks->counter > 3)
		bigger_than_3(stacks);
	
}

int main(int argc, char *argv[])
{
	t_stacks stacks;
	
	stacks.counter = 0;
	stacks.bottom_a = -1;
	stacks.bottom_b = -1;
	check_arguments(argc, argv, &stacks);
	check_duplicated(&stacks);
	if(check_sorted(&stacks))
		{
			if (stacks.stacka)
				free(stacks.stacka);
			exit(-1);
		}
	else
		push_swap(&stacks);
	free(stacks.stacka);	
	return (0);
}
