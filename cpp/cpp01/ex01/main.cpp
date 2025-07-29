/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:21:49 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/07/29 15:36:07 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{	
	Zombie *zombies = zombieHorde(10,"Hell_Zombie");
	for (int i = 0; i < 10;i++)
	{
		zombies[i].announce();
	}
	delete []zombies;
	return (0);
}