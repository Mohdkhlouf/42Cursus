/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:25:21 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/01/15 09:28:48 by mkhlouf          ###   ########.fr       */
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

void print_free_exit(t_stacks *stacks, char *sms)
{
    ft_printf("Error\n%s", sms);
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
	while(j <= stack->top_a)
	{
		ft_printf("%d ", stack->stacka[j]);
		j++;
	}
    ft_printf("#\n");
    j = 0;
    ft_printf("stack b:#");
    while(j <= stack->top_b)
	{
		ft_printf("%d ", stack->stackb[j]);
		j++;
	}
    ft_printf("#\n");
     ft_printf("******************************\n");
}
int get_bit_digit(int n, int dive_base)
{
   
	if (dive_base < 0)
		exit(-1);
	if (dive_base == 0)
		return (n % 10);
	while(dive_base > 0)
		{
			n = n/10;
            if ( n == 0)
                {
                    return (n);
                }
			dive_base--;
		}
		n = n % 10;
	return (n);
}