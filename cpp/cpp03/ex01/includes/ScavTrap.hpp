#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(const std::string &name);
        ~ScavTrap();
        ScavTrap(const ScavTrap &obj);
        ScavTrap & operator=(const ScavTrap &obj);
        void guardGate();
};

#endif