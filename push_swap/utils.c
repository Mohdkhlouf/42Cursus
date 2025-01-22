/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:25:21 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/01/22 13:42:21 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}

void	print_free_exit(t_stacks *stacks)
{
	ft_putstr_fd("Error\n", 2);
	free_stacks(stacks);
	exit(-1);
}

void	print_any_stack(int *stack, int len, char *msg)
{
	int	j;

	j = 0;
	ft_printf("******************************\n");
	ft_printf("%s#", msg);
	while (j < len)
	{
		ft_printf("%d ", stack[j]);
		j++;
	}
	ft_printf("#\n");
}

void	print_stack(t_stacks *stack)
{
	int	j;

	j = 0;
	ft_printf("******************************\n");
	ft_printf("stack a:#");
	while (j <= stack->bottom_a)
	{
		ft_printf("%d ", stack->stacka[j]);
		j++;
	}
	ft_printf("#\n");
	j = 0;
	ft_printf("stack b:#");
	while (j <= stack->bottom_b)
	{
		ft_printf("%d ", stack->stackb[j]);
		j++;
	}
	ft_printf("#\n");
	ft_printf("******************************\n");
}

int	get_bit_digit(int n, int dive_base)
{
	int	i;

	i = 0;
	if (dive_base < 0)
		return (-1);
	while (i < dive_base)
	{
		if (n == 0)
			return (0);
		n /= 10;
		i++;
	}
	return (n % 10);
}
