#include "FragTrap.hpp"

FragTrap::FragTrap():ClapTrap(){}

FragTrap::FragTrap(const std::string &name): ClapTrap(name)
		{
			std::cout<<"FragTrap parametrized constructor is called.\n";
			hit_points_ = 100;
			energy_points_ = 100;
			attack_damage_ = 30;
		}

FragTrap::~FragTrap(){
	std::cout<<"FragTrap "<<name_<<" Destructor is called. \n";
}
FragTrap::FragTrap(const FragTrap &obj){
	std::cout<<"FragTrap copy constructor is called \n";
	*this = obj;
}

FragTrap & FragTrap::operator=(const FragTrap &obj)
{
	std::cout<<"FragTrap equal operator overloading constructor is called \n";
	if(this == &obj)
		return (*this);
	*this = obj;
	return (*this);		
}

void FragTrap::attack(const std::string &target)
{
    if(energy_points_ == 0)
        std::cout<<"FragTrap "<<name_<<" cannot attack because it has no Energy points left.\n";
    else if(hit_points_ == 0)
        std::cout<<"FragTrap "<<name_<<" cannot attack because it has no Hit points left.\n";
    else
    {
        std::cout<<"FragTrap "<<name_<<" attacks "<<target
                 <<" causing "<<this->attack_damage_<<" points of damage!\n";
        energy_points_--;
    }
}

void FragTrap::highFivesGuys(void)
{
	if(hit_points_ == 0 || energy_points_ == 0)
		std::cout<<"FragTrap "<<name_<<"is dead and cannot say High Five.\n";
	std::cout<<"FragTrap "<<name_<<" says: High Five,✋ \n";
}