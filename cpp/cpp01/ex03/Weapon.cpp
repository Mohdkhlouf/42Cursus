/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:51:01 by mkhlouf           #+#    #+#             */
/*   Updated: 2025/07/22 12:09:28 by mkhlouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

	const std::string& Weapon::getType()
	{
		return (type);
	}
	
	void Weapon::setStype(std::string type)
	{
		this->type = type;
	}