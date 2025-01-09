/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:51 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/01/09 16:27:37 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_swap(t_stacks *stacks)
{
	int j;

	j = 0;
	// print it for test
	ft_printf("Welcome to push swap\n");
	while(j < stacks->counter)
	{
		ft_printf("%d\n", stacks->arr[j]);
		j++;
	}
}

void check_arguments(int argc, char *argv[], t_stacks *stacks)
{
if (argc== 1)
	{
		ft_printf("No arguments");
		exit(-1);
	}
else if (argc == 2)
	one_arg(argv[1], stacks);
else if (argc > 2)
	multi_args(argc, argv, stacks);
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
	free(stacks.arr);	
	return (0);
}
