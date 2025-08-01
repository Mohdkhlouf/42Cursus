#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"


int main(void)
{   
    ScavTrap obj2("Mezo");
    obj2.print();
    obj2.takeDamage(3);
    obj2.print();
    obj2.beRepaired(3);
    obj2.print();
    obj2.takeDamage(7);
    obj2.print();
    obj2.beRepaired(10);
    obj2.print();
    obj2.takeDamage(10);
    obj2.print();
    obj2.takeDamage(1);
    obj2.print();
    obj2.beRepaired(1);
    obj2.print();
    obj2.guardGate();
    return (0);
}