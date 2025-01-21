/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:31:18 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/01/22 01:12:24 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_free_exit_str(t_stacks *stacks, char **str)
{
	ft_putstr_fd("Error\n", 2);
    ft_free(str);
	free_stacks(stacks);
    exit(-1);
}

long is_not_oflow_str(long n, t_stacks *stacks, char **str)
{
	if(n > INT_MAX || n < INT_MIN)
		print_free_exit_str(stacks,str);
	return (n);
}

void multi_args_one(int len, char **str, t_stacks *stacks)
{
	int i;
	
	i = 0;
	stacks->stacka = malloc (len *sizeof (int));
	if (!stacks->stacka)
		print_free_exit_str(stacks, str);
	while (str[i])
	{
		if(ft_number(str[i]))
			i++;
		else
			print_free_exit_str(stacks, str);
	}
	i = 0;
	while (str[i])
		{
			stacks->stacka[i] = is_not_oflow_str(ft_atoi(str[i]), stacks, str);
			stacks->counter += 1;
			i++;
		}
	ft_free(str);
}

void one_arg(char *str, t_stacks *stacks)
{
	int i;
	char **arr;
	int str_len;
	
	i = 0;
	str_len = 0;
	if(ft_strlen(str) == 0 || str == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		free_stacks(stacks);
		exit(-1);
	}
	arr = ft_split(str, ' ');
	if(!arr)
		exit_free(stacks, arr);
	while (arr[i])
		{
			str_len++;
			i++;
		}
	if(str_len == 1)
		exit_free(stacks, arr);
	multi_args_one(str_len,arr, stacks);
}
