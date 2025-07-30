/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:06:24 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/07/30 18:44:01 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

void test_divide_by_zero(){
	Fixed a(5);
	Fixed b (0);
	Fixed c = a/b;
}

void test_comparing_operators(){
	Fixed a(5);
	Fixed b(10);

	const Fixed c(10);
	const Fixed d(10);
	
	std::cout<<"Max value a&b: "<<Fixed::max(a,b) <<"\n";
	std::cout<<"Min value a&b: "<<Fixed::min(a,b) <<"\n";
	std::cout<<"Const Max value c&d: "<<Fixed::max( c, d) <<"\n";
	std::cout<<"Const Min value c&d: "<<Fixed::min( c, d) <<"\n";

	if (a>b)
		std::cout<<"a>b True: a is larger than b\n";
	else
		std::cout<<"a>b False: a is smaller than b\n";

	if (a<b)
		std::cout<<"a<b True.\n";
	else
		std::cout<<"a<b False.\n";

	if (a==b)
		std::cout<<"a==b True.\n";
	else
		std::cout<<"a==b False.\n";

	
	if (a!=b)
		std::cout<<"a!=b is True.\n";
	else
		std::cout<<"a!=b  is False. \n";

	if (c>=d)
		std::cout<<"a>=b is True.\n";
	else
		std::cout<<"a>=b  is False.\n";

	if (c<=d)
		std::cout<<"a<=b is True.\n";
	else
		std::cout<<"a<=b  is False.\n";
	
}

void test_numeric_operators(){
	Fixed a(5);
	Fixed b(10);

	std::cout<<"Test + operator: " << a+b << "\n";
	std::cout<<"Test - operator: " << b-a << "\n";
	std::cout<<"Test * operator: " << a*b << "\n";
	std::cout<<"Test / operator: " << b/a << "\n";
}

void test_inc_dec_operators()
{
	Fixed a(5);

	std::cout<<a++<<"\n";
	a--;
	std::cout<<a--<<"\n";
	a++;
	std::cout<<++a<<"\n";
	--a;
	std::cout<<--a<<"\n";
	++a;
}

int	main(void)
{
	// test for bad fractional bits
	// change the value from the hpp file to be something else than 8.

//test_divide_by_zero();	// test the division value by zero
// test_comparing_operators(); 	// test Comparing operators
// test_numeric_operators(); / test numeric operators
// test_inc_dec_operators();  // increment and decrement tests
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
return (0);
}