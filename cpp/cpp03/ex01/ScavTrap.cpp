#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name)
    :ClapTrap(name) {
    hit_points_(100);
    energy_points_(50);
    attack_damage_(20);        
 }
ScavTrap::~ScavTrap(){}