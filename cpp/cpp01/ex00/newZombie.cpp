/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:20:50 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/07/29 15:34:07 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
	try
	{
		Zombie *ptr = new Zombie(name);
		return (ptr);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
		exit(EXIT_FAILURE);
	}
}