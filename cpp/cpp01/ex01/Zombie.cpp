/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:21:53 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/07/22 11:21:54 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie::Zombie()
{
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie(){ 
	std::cout<<this->name<<" is destroyed\n";
}

void Zombie::announce(){
	std::cout<<this->name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}

void Zombie::setName(std::string name){
	this->name = name;
}
