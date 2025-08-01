#include "../includes/ScavTrap.hpp"

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
     if(this != &obj)
    {
        name_ = obj.name_;
        attack_damage_ = obj.attack_damage_;
        hit_points_ = obj.hit_points_;
        energy_points_ = obj.energy_points_;
    }
    return(*this);
}

void ScavTrap::guardGate(){
    std::cout<<"ScavTrap " <<name_ <<" is now in Gate Kepper mpde\n";
}