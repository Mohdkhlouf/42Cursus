/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:21:21 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/07/22 11:21:22 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		for(int i = 1; argv[i]; i++)
		{
			for(int j=0;argv[i][j]; j++)
				std::cout << (char)std::toupper(argv[i][j]);
		}
		std::cout<<std::endl;
	return (0);
}