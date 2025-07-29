
#include "HumanB.hpp"

void HumanB::attack()
{
	if(!weapon_)
		{
			std::cout<<"Cannot attack without a weapon."<<std::endl;
			exit(EXIT_FAILURE);
		}
	std::cout<<name_<<" attacks with their "<<weapon_->getType()<<"\n";
}

void HumanB::setWeapon(Weapon &web){
	weapon_ = &web;
}

HumanB::HumanB(std::string name){
	name_ = name;
}

HumanB::~HumanB(){
}