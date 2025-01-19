/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:25:21 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/01/17 21:39:27 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_free(char **arr)
{
    int i = 0;

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

void print_free_exit(t_stacks *stacks)
{
    ft_putstr_fd("Error\n", 2);
    if (stacks->stacka)
        free(stacks->stacka);
    exit(-1);
}

void print_any_stack(int *stack, int len, char *msg)
{
    int j;

    j = 0;
    ft_printf("******************************\n");
    ft_printf("%s#", msg);
	while(j < len)
	{
		ft_printf("%d ", stack[j]);
		j++;
	}
    ft_printf("#\n");
}

void print_stack(t_stacks *stack)
{
    int j;

    j = 0;
    ft_printf("******************************\n");
    ft_printf("stack a:#");
	while(j <= stack->bottom_a)
	{
		ft_printf("%d ", stack->stacka[j]);
		j++;
	}
    ft_printf("#\n");
    j = 0;
    ft_printf("stack b:#");
    while(j <= stack->bottom_b)
	{
		ft_printf("%d ", stack->stackb[j]);
		j++;
	}
    ft_printf("#\n");
     ft_printf("******************************\n");
}
int get_bit_digit(int n, int dive_base)
{
    if (dive_base < 0)  // Invalid input for dive_base
        return -1;

    // Loop to remove the last `dive_base` digits
    for (int i = 0; i < dive_base; i++)
    {
        if (n == 0)  // If n becomes 0, return 0 as there are no more digits
            return 0;
        n /= 10;  // Remove the last digit
    }

    return n % 10;  // Return the current last digit
}
