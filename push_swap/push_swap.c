/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:51 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/01/06 20:01:32 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void arg_as_numbers(int argc, char **str, t_stacks *stacks)
{
	int i;
	int j;
	char *all_str;
	
	i = 1;
	j = 0;
	j = argc;	
	while ((i < argc ) && (j >= 0))
		{
		if(ft_atoi(str[i]))
		{	
			stacks->counter += 1;
			i++;
			j--;
		}
		else
		{
			printf("error not all arguments are numbers!\n");
			// free(stacks->stacka);
			exit (-1);
		}
	}
}
void arg_as_string(char *str, t_stacks *stacks)
{
	printf("Test");
}
int main(int argc, char *argv[])
{
	t_stacks stacks;
	
	stacks.counter = 0;
	
	if (argc == 2)
		arg_as_string(argv[2], &stacks);
	if (argc > 2)
	{
		arg_as_numbers(argc, argv, &stacks);
	}
	printf("Main Counter is:#%d#\n", stacks.counter);
	return (0);
}