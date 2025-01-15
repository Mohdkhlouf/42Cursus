/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:51 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/01/15 21:25:46 by mkhlouf          ###   ########.fr       */
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
	// ft_printf("how many digits  %d\n", digits);
}

void max_number_digits(t_stacks *stack)
{
	int i;
	int max;
	int *new_stack;
	
	i = 0;
	max = 0;
	new_stack = malloc(sizeof(stack->stacka) * stack->counter);
	if (!new_stack)
		print_free_exit(stack);
	ft_memcpy(new_stack, stack->stacka, stack->counter);
	while (i < stack->counter)
	{
		if (new_stack[i] < 0)
			new_stack[i]*= -1;
		if (new_stack[i] > max)
			max = new_stack[i];
		i++;
	}
	stack->max_int = max;
	// ft_printf("Max digits number %d\n", stack->max_int);
	how_many_digits(stack);
}

int base(int n)
{
	int result;
	
	result = 1;
	while (n > 0)
	{
		result = result * 10;
		n--;
	}
	return (result);
}
int have_values_in(int *stack, int top, int j , int div_base)
{
	int i;
	int have_value;
	
	i = top;
	have_value = 0;
	while (i >= 0)
	{
		if (get_bit_digit((stack[i]), div_base) == j)
			{
				have_value = 1;
				break;
			}
		i--;
	}
	return (have_value);
}

int have_values(int *stack, int top, int j , int div_base)
{
	int i;
	int have_value;
	
	i = top;
	have_value = 0;
	while (i >= 0)
	{
		
		if (get_bit_digit((stack[i]), div_base) == j)
			{
				have_value = 1;
				break;
			}
		i--;
	}
	return (have_value);
}

void pass_radix_b(t_stacks *stack, int div_base)
{
	int j;
	int sign;
	int i;

	j = 0;
	sign = 1;
	i = stack->bottom_b;
	// printf("I am on stacl B radix pass\n");
	while (j <= 9 && stack->bottom_b != -1)
	{
		i = stack->bottom_b;
		print_stack(stack);
		if(have_values(stack->stackb, i, j, div_base))
		{
			// printf(" B radix pass Test %d,%d,%d\n", div_base, j, i);
			while (i >= 0)
			{
				if (stack->stackb[stack->bottom_b] < 0)
					sign *= -1;
				if(get_bit_digit((stack->stackb[stack->bottom_b] * sign),div_base) == j)
					push_a(stack);
				else
					reverse_rotate_b(stack);
				sign = 1;
				i--;
			}
		}
		j++;
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
void pass_radix_a(t_stacks *stack, int div_base)
{
	int j;
	int sign;
	int i;

	j = 0;
	sign = 1;
	i = stack->bottom_a;
	// printf("I am on stacl A radix pass\n");
	// printf("digit %d\n", (((stack->stacka[stack->bottom_a] * sign) >> div_base) & 1));
	while (j <= 9 && stack->bottom_a != -1)
	{
		i = stack->bottom_a;
		if(have_values(stack->stacka, i, j, div_base))
		{
			while (i >= 0)
			{
				if(get_bit_digit((stack->stacka[stack->bottom_a] * sign),div_base) == j)
					push_b(stack);
				
				else
				{
		
						reverse_rotate_a(stack);  // Rotate only if there are more valid values
	
				}
				sign = 1;
				i--;
			}
		}
		j++;
	}
	
}

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
                // Swap arr[i] and arr[j]
                int temp = stack->sorted_stack[i];
                stack->sorted_stack[i] = stack->sorted_stack[j];
                stack->sorted_stack[j] = temp;
            }
            j++;
        }
        i++;
    }
}

void push_negative(t_stacks *stack)
{
	int i;

	i = stack->bottom_a;
	while(i >= 0)
	{
		if (stack->stacka[stack->bottom_a] < 0)
		{
				push_b(stack);
		}
		reverse_rotate_a(stack);
		i--;
	}
}


void big_stack(t_stacks *stack)
{
	int i;

	i = 0;
	
	sort_array(stack);
	set_positions(stack);
	max_number_digits(stack);
	while (i < stack->digits_number)
	{
		pass_radix_a(stack, i);
		push_all_b(stack);
		i++;	
	}
	// rotate_all_a(stack);
	// print_stack(stack);	
}

void sort3(t_stacks *stack)
{
	if (stack->stacka[0] > stack->stacka[1] && stack->stacka[0] > stack->stacka[2]) 
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


void push_swap(t_stacks *stacks)
{

	stacks->stackb = malloc (stacks->counter * sizeof(int));
	if (!stacks->stackb)
		print_free_exit(stacks);
	stacks->bottom_a = 0;
	if (stacks->counter == 3)
		sort3(stacks);
	if (stacks->counter > 3)
		big_stack(stacks);
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
