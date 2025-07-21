#include "Zombie.hpp"

int main()
{
	Zombie *z2 = newZombie("newZombie");
	if (z2)
	{
		z2->announce();
		delete z2;
		randomChump("new Zombie");
		return (0);
	}
	else
		return (1);
}