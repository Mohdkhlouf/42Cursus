#include "Character.hpp"
#include "AMateria.hpp"

Character::Character():ICharacter(){
	std::cout<<"Character default constructor called."<<std::endl;
	for (int i = 0; i < 4; i++)
	{
		inventory_[i] = nullptr;
	}
}
Character::~Character(){
	std::cout<<"Character destructor called."<<std::endl;
}

std::string const & Character::getName() const{
	return (name);
}



void Character::equip(AMateria* m) {

}



void Character::unequip(int idx) {

}


void Character::use(int idx, ICharacter& target){

}