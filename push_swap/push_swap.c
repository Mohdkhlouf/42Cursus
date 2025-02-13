/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:51 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/02/11 19:14:18 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bigger_than_3(t_stacks *stacks)
{
	sort_array(stacks);
	set_positions(stacks);
	max_number_digits(stacks);
	if (stacks->counter < 10)
		up_to_10(stacks);
	else
		radix_bitwise(stacks);
}

void	push_swap(t_stacks *stacks)
{
	stacks->stackb = malloc(stacks->counter * sizeof(int));
	if (!stacks->stackb)
		print_free_exit(stacks);
	stacks->bottom_a = stacks->counter - 1;
	if (stacks->counter == 2)
	{
		if (stacks->stacka[0] > stacks->stacka[1])
			swap_a(stacks);
	}
	else if (stacks->counter == 3)
		sort3(stacks);
	else if (stacks->counter > 3)
		bigger_than_3(stacks);
}

void	initial_values(t_stacks *stacks)
{
	stacks->stacka = NULL;
	stacks->stackb = NULL;
	stacks->sorted_stack = NULL;
	stacks->orginal = NULL;
	stacks->counter = 0;
	stacks->bottom_a = -1;
	stacks->bottom_b = -1;
	stacks->sorted = 0;
	stacks->position = 0;
}

int	main(int argc, char *argv[])
{
	t_stacks	*stacks;
	static t_stacks stacks;
	static t_stacks stacks[1];

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		exit(-1);
	initial_values(stacks);
	check_arguments(argc, argv, stacks);
	check_duplicated(stacks);
	if (check_sorted(stacks))
	{
		if (stacks->stacka)
			free_stacks(stacks);
		exit(-1);
	}
	else
		push_swap(stacks);
	free_stacks(stacks);
	return (0);
}
1 2 3 4 5
0 1 2 3 4