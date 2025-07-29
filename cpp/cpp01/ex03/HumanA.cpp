/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:50:55 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/07/29 15:20:27 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void HumanA::attack()
{
	std::cout<<name_<<" attacks with their "<<weapon_.getType()<<"\n";
}

HumanA::HumanA(std::string name, Weapon& weapon):name_(name),weapon_(weapon){}

HumanA::~HumanA(){}
