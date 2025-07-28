#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
    std::cout<<"ScavTrap constructor started.\n";
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

void ScavTrap::guardGate(){
    std::cout<<"ScavTrap " <<name_ <<" is now in Gate Kepper mpde\n";
}