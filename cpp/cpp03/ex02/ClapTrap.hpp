#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>
class ClapTrap{

    protected:
        std::string name_;
        int hit_points_;
        int energy_points_;
        int attack_damage_;
    
    public:
        ClapTrap();
        ClapTrap(const std::string &name);
        ClapTrap(const ClapTrap &obj);
        ~ClapTrap();
        ClapTrap& operator=(const ClapTrap &obj);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        int getHitPoints();
        int getEnergyPoints();
        int getAttackDamage();
        void print();

};

std::ostream &operator<<(std::ostream &os, ClapTrap & obj);
#endif