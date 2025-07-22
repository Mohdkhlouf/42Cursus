/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:23:21 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/07/22 11:46:10 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;
	
	std::cout<<"string address: "<<&str<<"\n";
	std::cout<<"stringPTR held address: "<<stringPTR<<"\n";
	std::cout<<"stringREF held address: "<<&stringREF<<"\n";

	std::cout<<"value of the string: "<<str<<"\n";
	std::cout<<"value held by stringPTR: "<<*stringPTR<<"\n";
	std::cout<<"value held by stringREF: "<<stringREF<<"\n";

	return (EXIT_SUCCESS);
}