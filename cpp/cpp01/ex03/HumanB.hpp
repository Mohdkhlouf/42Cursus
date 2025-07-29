#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string name_;
		Weapon *weapon_ = nullptr;
	public:
		void attack();
		void setWeapon(Weapon &web);
		HumanB(std::string name);
		~HumanB();
};

#endif