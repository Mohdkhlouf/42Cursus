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
        ScavTrap(ScavTrap &obj);
        ScavTrap & operator=(ScavTrap &obj);
        void guardGate();
        void attack(const std::string& target);
};

#endif