#include "Character.hpp"
#include "AMateria.hpp"

Character::Character():ICharacter(){
	std::cout<<"Character default constructor called."<<std::endl;
	for (int i = 0; i < 4; i++)
	{
		inventory_[i] = nullptr;
	}
}

Character::Character(const Character &obj){
	for (int i = 0; i < 4; i++)
	{
		inventory_[i] = obj.inventory_[i]->clone();
	}
}

Character& Character::operator=(const Character& obj){
	if (this != &obj)
	{
		
		for (int i = 0; i < 4; i++)
	{
		delete obj.inventory_[i];
		inventory_[i] = obj.inventory_[i]->clone();

	}
	}
	return (*this);
}



Character::~Character(){
	std::cout<<"Character destructor called."<<std::endl;
	delete [] inventory_;
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