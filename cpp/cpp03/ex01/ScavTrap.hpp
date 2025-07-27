#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap
{
    ScavTrap(const std::string &name): ClapTrap(name);
    ~ScavTrap();
};

#endif