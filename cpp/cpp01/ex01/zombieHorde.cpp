/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:21:56 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/07/29 15:37:10 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{

	try
	{
		Zombie *zombies = new Zombie[N];
		for (int i = 0; i < N; i++)
			zombies[i].setName(name);
		return (zombies);
	}
	catch (std::bad_alloc &e)
	{
		std::cout <<e.what() << std::endl;
		exit(EXIT_FAILURE);
	}
}