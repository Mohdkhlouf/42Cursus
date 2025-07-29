#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
	private:
		std::string type_;

	public:
		const std::string& getType();
		void setType(std::string type);
		Weapon();
		Weapon(std::string type);
		~Weapon();
};

#endif
