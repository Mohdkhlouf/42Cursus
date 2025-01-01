/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:49:17 by mkhlouf           #+#    #+#             */
/*   Updated: 2024/11/21 10:46:27 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

void	ft_putchar(char c, int *count);
void	ft_putnbr(int n, int *count);
void	ft_putstr(char *s, int *count);
void	ft_putnbr_unsigned(unsigned long long n, int *count);
void	ft_putnbr_hex(uint64_t n, int *count, unsigned char c);
void	ft_putptr(void *n, int *count);
int		ft_printf(const char *num, ...);

#endif
