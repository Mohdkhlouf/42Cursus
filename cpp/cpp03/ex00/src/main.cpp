#include "../includes/ClapTrap.hpp"

int main(void)
{   
    ClapTrap obj1("mohammad");
    obj1.takeDamage(3);
    obj1.print();
    obj1.beRepaired(3);
    obj1.print();
    obj1.takeDamage(7);
    obj1.print();
    obj1.beRepaired(10);
    obj1.print();
    obj1.takeDamage(10);
    obj1.print();
    obj1.takeDamage(1);
    obj1.print();
    obj1.beRepaired(1);
    obj1.print();
    return (0);
}