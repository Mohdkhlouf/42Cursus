/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:31:18 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/01/23 22:48:05 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_free_exit_str(t_stacks *stacks, char **str)
{
	ft_putstr_fd("Error\n", 2);
	ft_free(str);
	free_stacks(stacks);
	exit(-1);
}

long	is_not_oflow_str(long n, t_stacks *stacks, char **str)
{
	if (n > INT_MAX || n < INT_MIN)
		print_free_exit_str(stacks, str);
	return (n);
}

void	multi_args_one(int len, char **str, t_stacks *stacks)
{
	int	i;

	i = 0;
	stacks->stacka = malloc(len * sizeof(int));
	if (!stacks->stacka)
		print_free_exit_str(stacks, str);
	while (str[i])
	{
		if (ft_strlen(str[i]) > 15)
			print_free_exit_str(stacks, str);
		if (ft_number(str[i]))
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

void check_empty(char *str, t_stacks *stacks)
{
	long unsigned i;
	int have_spaces;

	i = 0;
	have_spaces = 1;
	while(i < ft_strlen(str))
	{
		if(str[i] != ' ')
		{
			have_spaces = 0;
			break;
		}
		i++;
	}
	if(have_spaces == 1)
	{
		ft_putstr_fd("Error\n", 2);
		free_stacks(stacks);
		exit(-1);
	}
}

void	one_arg(char *str, t_stacks *stacks)
{
	int		i;
	char	**arr;
	int		str_len;

	i = 0;
	str_len = 0;
	if (ft_strlen(str) == 0 || str == NULL ) 
	{
		free_stacks(stacks);
		exit(-1);
	}
	check_empty(str, stacks);
	arr = ft_split(str, ' ');
	if (!arr)
		exit_free(stacks, arr);	
	while (arr[i])
	{
		str_len++;
		i++;
	}
	multi_args_one(str_len, arr, stacks);
}
