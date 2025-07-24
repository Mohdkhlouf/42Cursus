/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:06:24 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/07/24 19:29:10 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main()
{
	Fixed a;
	// Fixed const b(10);
	// Fixed const c(42.42f);
	// Fixed const d(b);
	a = Fixed(1234.4321f);

	return (EXIT_SUCCESS);
}