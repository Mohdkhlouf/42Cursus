/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:16:45 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/01/23 17:41:36 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stacks
{
	int	counter;
	int	*stacka;
	int	*stackb;
	int	*sorted_stack;
	int	*orginal;
	int	bottom_a;
	int	bottom_b;
	int	max_int;
	int	digits_number;
	int	digits_number_bitwise;
	int	sorted;
	int	position;
}		t_stacks;

int		ft_number(char *str);
void	print_free_exit(t_stacks *stacks);
void	ft_free(char **arr);
long	is_not_oflow(long n, t_stacks *stacks);
void	print_free_exit_str(t_stacks *stacks, char **str);
long	is_not_oflow_str(long n, t_stacks *stacks, char **str);
void	multi_args_one(int len, char **str, t_stacks *stacks);
void	one_arg(char *str, t_stacks *stacks);
void	multi_args(int argc, char **str, t_stacks *stacks);
void	check_duplicated(t_stacks *stacks);
bool	check_sorted(t_stacks *stacks);
void	check_arguments(int argc, char *argv[], t_stacks *stacks);
void	print_stack(t_stacks *stack);
void	swap_a(t_stacks *stack);
void	rotate_a(t_stacks *stack);
void	reverse_rotate_a(t_stacks *stack);
void	max_number_digits(t_stacks *stack);
void	push_b(t_stacks *stack);
void	reverse_rotate_b(t_stacks *stack);
void	push_a(t_stacks *stack);
int		get_bit_digit(int n, int dive_base);
void	push_all_b(t_stacks *stack);
void	print_any_stack(int *stack, int len, char *msg);
void	rotate_all_a(t_stacks *stack);
int		have_values(int *stack, int top, int j, int div_base);
int		have_values_in(int *stack, int top, int j, int div_base);
void	max_number_digits(t_stacks *stack);
void	how_many_digits(t_stacks *stack);
int		value_position(int *stack, int top, int j, int div_base);
void	sort3(t_stacks *stack);
void	sort_array(t_stacks *stack);
void	set_positions(t_stacks *stack);
void	radix_bitwise(t_stacks *stack);
void	pass_radix_bitwise(t_stacks *stack, int div_base);
int		get_bit_digit_bitwise(int n, int dive_base);
void	free_stacks(t_stacks *stacks);
void	exit_free(t_stacks *stacks, char **arr);
void	pass_radix_5(t_stacks *stack, int div_base);
void	up_to_10(t_stacks *stack);
void	radix_5(int bottom, t_stacks *stack, int div_base, int *j);

#endif