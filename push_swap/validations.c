/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:50:24 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/01/21 00:21:17 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void check_arguments(int argc, char *argv[], t_stacks *stacks)
{
if (argc== 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(-1);
	}
else if (argc == 2)
	one_arg(argv[1], stacks);
else if (argc > 2)
	multi_args(argc, argv, stacks);
}

int ft_number(char *str)
{
	int i;

	i = 0;
	if (ft_strchr(str,' '))
		return (0);
	while(str[i])
	{			
		if ((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i+1]) && !ft_isdigit(str[i-1]) )
			i++;
		if (ft_isdigit(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

bool check_sorted_radix(t_stacks *stacks, int i)
{
int j;

j = 1;
while (i < stacks->bottom_a)
{
	if(stacks->stacka[i] < stacks->stacka[j])
	{
		i++;
	}	
	else
	{
		return (false);
	}
	j = i + 1;
}
return (true);
}


bool check_sorted(t_stacks *stacks)
{
int i;
int j;

i = 0;
j = 1;
while (j < stacks->counter)
{
	if(stacks->stacka[i] < stacks->stacka[j])
			i++;
	else
		return (false);
	j = i + 1;
}
return (true);
}

void check_duplicated(t_stacks *stacks)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while(i < stacks->counter)
	{
		j = i + 1;
		while (j < stacks->counter )
		{
			if (stacks->stacka[i] == stacks->stacka[j])
				{
					print_free_exit(stacks);
					exit(-1);
				}
			j++;
		}
		i++;
	}
}
