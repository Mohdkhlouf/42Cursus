/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:45 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/01/09 16:04:51 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct s_stacks
{
	int counter;
	int *arr;
	int	*stacka;
	int	*stachb;
}			t_stacks;

int ft_number(char *str);
void print_free_exit(t_stacks *stacks, char *sms);
void ft_free(char **arr);
long is_not_oflow(long n, t_stacks *stacks);
void print_free_exit_str(t_stacks *stacks, char **str, char *sms);
long is_not_oflow_str(long n, t_stacks *stacks, char **str);
void multi_args_one(int len, char **str, t_stacks *stacks);
void one_arg(char *str, t_stacks *stacks);
void multi_args(int argc, char **str, t_stacks *stacks);
void check_duplicated(t_stacks *stacks);
bool check_sorted(t_stacks *stacks);


#endif