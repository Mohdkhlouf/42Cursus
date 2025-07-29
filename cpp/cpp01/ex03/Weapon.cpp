/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:51:01 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/07/29 14:42:46 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

	const std::string& Weapon::getType()
	{
		return (type_);
	}
	
	void Weapon::setType(std::string type)
	{
		type_ = type;
	}

	Weapon::Weapon(std::string type)
	{
		type_ = type;
	}

	Weapon::Weapon()
	{}
	
	Weapon::~Weapon()
	{}