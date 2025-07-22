/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:20:44 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/07/22 11:20:46 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *z2 = newZombie("newZombie");
	if (z2)
	{
		z2->announce();
		delete z2;
		randomChump("new Zombie");
		return (EXIT_SUCCESS);
	}
	else
		return (EXIT_FAILURE);
}