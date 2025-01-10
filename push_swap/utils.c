/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:25:21 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/01/10 18:06:46 by mkhlouf          ###   ########.fr       */
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

void print_stack(t_stacks *stack)
{
    int j;

    j = 0;
	while(j < stack->counter)
	{
		ft_printf("%d ", stack->stacka[j]);
		j++;
	}
}
