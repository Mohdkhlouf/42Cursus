/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:51 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/01/03 17:36:53 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int main(int argc, char *argv[])
{
	t_stacks stacks;
	int i;

	i = 0;
	stacks.stacka = malloc(argc * sizeof (int) - 1);
	ft_strcpy(stacks.stacka, *argv);
	while (i < argc -1)
		{
			printf("%d\n",stacks.stacka[i]);
			i++;
		}
	return (0);
}