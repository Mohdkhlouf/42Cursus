#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"



int main(void)
{   

    std::cout<<"Testing ClapTrap \n";
    ClapTrap obj1("ClapBaby");
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

    std::cout<<"\n\nTesting ScavTrap \n";
    ScavTrap scav_obj("ScavBoss");
    scav_obj.takeDamage(3);
    scav_obj.print();
    scav_obj.beRepaired(3);
    scav_obj.print();
    scav_obj.takeDamage(7);
    scav_obj.print();
    scav_obj.beRepaired(10);
    scav_obj.print();
    scav_obj.takeDamage(10);
    scav_obj.print();
    scav_obj.takeDamage(1);
    scav_obj.print();
    scav_obj.beRepaired(1);
    scav_obj.print();

    std::cout<<"\n\nTesting FragTrap \n";
    FragTrap frag_obj("FragKing");
    frag_obj.takeDamage(3);
    frag_obj.print();
    frag_obj.beRepaired(3);
    frag_obj.print();
    frag_obj.takeDamage(7);
    frag_obj.print();
    frag_obj.beRepaired(10);
    frag_obj.print();
    frag_obj.takeDamage(10);
    frag_obj.print();
    frag_obj.takeDamage(1);
    frag_obj.print();
    frag_obj.beRepaired(1);
    frag_obj.print();

    return (0);
}