#include "ScavTrap.hpp"
ScavTrap::ScavTrap():ClapTrap(){
    std::cout<<"ScavTrap default constructor started.\n";
};

ScavTrap::ScavTrap(const std::string &name):ClapTrap(name){
    std::cout<<"ScavTrap parameterized constructor started.\n";
    hit_points_ = 100;
    energy_points_ = 50;
    attack_damage_ = 20;
};  

ScavTrap::~ScavTrap(){
    std::cout<<"ScavTrap destructor called.\n";
}
ScavTrap::ScavTrap(const ScavTrap &obj)
{
    std::cout<<"ScavTrap copy constructor called.\n";
    *this = obj;
}
ScavTrap & ScavTrap::operator=(const ScavTrap &obj)
{
    std::cout<<"ScavTrap equal operator overloading called.\n";
    if(this == &obj)
        return (*this);
    *this = obj;
    return (*this);
}

void ScavTrap::guardGate(){
    std::cout<<"ScavTrap " <<name_ <<" is now in Gate Kepper mpde\n";
}