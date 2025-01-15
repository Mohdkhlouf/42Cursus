/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:36:17 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/01/15 16:51:05 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


long is_not_oflow(long n, t_stacks *stacks)
{
	if(n > INT_MAX || n < INT_MIN)
		{
			ft_putstr_fd("Error\n",2);
			free(stacks->stacka);
			exit(-1);
		}
	return (n);
}

void multi_args(int argc, char **str, t_stacks *stacks)
{
	int i;
	int j;
	
	i = 1;
	j = 0;
	stacks->stacka = malloc (argc *sizeof (int));
	if (!stacks->stacka)
		print_free_exit(stacks);
	while (str[i])
	{
		if(ft_number(str[i]))
			i++;
		else
			print_free_exit(stacks);
	}
	i = 1;
	while (str[i])
		{
			stacks->stacka[j] = is_not_oflow(ft_atoi(str[i]), stacks);
			stacks->counter += 1;
			i++;
			j++;
		}
}

