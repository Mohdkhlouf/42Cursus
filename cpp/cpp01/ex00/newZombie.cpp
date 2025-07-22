/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:20:50 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/07/22 11:20:51 by mkhlouf          ###   ########.fr       */
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
		std::cerr << e.what() << '\n';
		return (nullptr);
	}
}