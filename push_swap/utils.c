/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:25:21 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/01/09 16:23:58 by mkhlouf          ###   ########.fr       */
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
    if (stacks->arr)
        free(stacks->arr);
    exit(-1);
}

int ft_number(char *str)
{
	int i;

	i = 0;
	if (ft_strchr(str,' '))
		return (0);
	while(str[i])
	{			
		if ((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i+1]))
			i++;
		if (ft_isdigit(str[i]))
			i++;
		else
			return (0);
	}
	
	return (1);
}

bool check_sorted(t_stacks *stacks)
{
int i;
int j;

i = 0;
j = 1;
while (j < stacks->counter)
{
	
	if(stacks->arr[i] < stacks->arr[j])
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
			if (stacks->arr[i] == stacks->arr[j])
				{
					print_free_exit(stacks, "there are dupllicated numbers");
					exit(-1);
				}
			j++;
		}
		i++;
	}
}