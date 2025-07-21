#include "Zombie.hpp"

int main()
{	
	Zombie *zombies = zombieHorde(10,"Hell_Zombie");
	if(!zombies)
		return(1);
	for (int i = 0; i < 10;i++)
	{
		zombies[i].announce();
	}
	delete []zombies;
	return (0);
}