/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammad <mohammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:45 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/01/14 23:10:58 by mohammad         ###   ########.fr       */
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
	int *stacka;
	int	*stackb;
	int *sorted_stack;
	int *orginal;
	int top_a;
	int top_b;
	int max_int;
	int digits_number;
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
void check_arguments(int argc, char *argv[], t_stacks *stacks);
void print_stack(t_stacks *stack);
void swap_a(t_stacks *stack);
void rotate_a(t_stacks *stack);
void reverse_rotate_a(t_stacks *stack);
void max_number_digits(t_stacks *stack);
void push_b(t_stacks *stack);
void reverse_rotate_b(t_stacks *stack);
void push_a(t_stacks *stack);
int get_bit_digit(int n, int dive_base);
void push_all_b(t_stacks *stack);
void print_any_stack(int *stack, int len, char *msg);
void rotate_all_a(t_stacks *stack);
#endif