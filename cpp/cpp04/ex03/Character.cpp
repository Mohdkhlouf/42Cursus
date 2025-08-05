#include "Character.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"


Character::Character(){
	// std::cout<<"Character default constructor called."<<std::endl;
	for (int i = 0; i < 4; i++)
	{
		inventory_[i] = nullptr;
	}
	name_="unnammed";
}


Character::Character(std::string name)
{
	name_ = name;
	for (int i = 0; i < 4; i++)
	{
		inventory_[i] = nullptr;
	}
}


Character::Character(const Character &obj){
	name_=obj.name_;
	for (int i = 0; i < 4; i++)
	{
		if(obj.inventory_[i])
			inventory_[i] = obj.inventory_[i]->clone();
		else
			inventory_[i] = nullptr;
	}
}

Character& Character::operator=(const Character& obj){
	if (this != &obj)
	{
		name_=obj.name_;
		for (int i = 0; i < 4; i++)
		{
			if(inventory_[i])
			{
				 delete inventory_[i];
				 inventory_[i] = nullptr;
			}
			if (obj.inventory_[i])
				inventory_[i] = obj.inventory_[i]->clone();
			else
				inventory_[i] = nullptr;
		}
	}
	return (*this);
}

Character::~Character(){
	// std::cout<<"Character destructor called."<<std::endl;
	for (int i = 0; i < 4; i++)
	{
		if(inventory_[i])
			delete inventory_[i];
		inventory_[i] = nullptr;
	}
}

std::string const & Character::getName() const{
	return (name_);
}



void Character::equip(AMateria* m) {
	if (!m)
		return;
	for (int i = 0; i < 4; i++) {
        if (inventory_[i] == m) {
            return;
        }
    }
	for (int i = 0; i < 4 ; i++)
	{
		if (!inventory_[i])
		{
			inventory_[i] = m;
			return;
		}
			
	}
}


void Character::unequip(int idx) {
    if (idx >= 4 || idx < 0 || !inventory_[idx]){
return;
	}
    	
	inventory_[idx] = nullptr;
}


void Character::use(int idx, ICharacter& target){
    if (idx >= 4 || idx < 0 || !inventory_[idx]){
		return;
	}
	inventory_[idx]->use(target);
}