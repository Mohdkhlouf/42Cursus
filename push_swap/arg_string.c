/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:31:18 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/01/10 15:06:38 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_free_exit_str(t_stacks *stacks, char **str, char *msg)
{
	ft_printf("Error\n%s", msg);
    if (stacks->stacka)
        free(stacks->stacka);
    ft_free(str);
    exit(-1);
}

long is_not_oflow_str(long n, t_stacks *stacks, char **str)
{
	if(n > INT_MAX || n < INT_MIN)
		print_free_exit_str(stacks,str,"Number is overflow");
	return (n);
}

void multi_args_one(int len, char **str, t_stacks *stacks)
{
	int i;
	
	i = 0;
	stacks->stacka = malloc (len *sizeof (int));
	if (!stacks->stacka)
		print_free_exit_str(stacks, str,"Malloc Failed");
	while (str[i])
	{
		if(ft_number(str[i]))
			i++;
		else
			print_free_exit_str(stacks, str,"Not a valid umber");
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
	arr = ft_split(str, ' ');
	if(!arr)
	{
		ft_free(arr);
		exit(-1);
	}
	while (arr[i])
		{
			str_len++;
			i++;
		}
	multi_args_one(str_len,arr, stacks);
}