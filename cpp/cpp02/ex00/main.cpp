/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:06:24 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/07/31 12:26:11 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main()
{
	std::cout<<"Testing Fixed constructor"<<std::endl;
	Fixed a;
	std::cout << a.getRawBits() << std::endl;
	
	std::cout<<"\n\nTesting Fixed copy constructor"<<std::endl;
	Fixed b(a);
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	
	std::cout<<"\n\nTesting Fixed assignment operator"<<std::endl;
	Fixed c;
	c = b;
	std::cout << c.getRawBits() << std::endl;

	std::cout<<"\n\nTesting Fixed setters and getters"<<std::endl;
	a.setRawBits(640);
	std::cout<<"A raw value is"<< a.getRawBits()<< std::endl;
	
	return (EXIT_SUCCESS);
}