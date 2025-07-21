#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{

	try
	{
		Zombie *zombies = new Zombie[N];
		for (int i = 0; i < N; i++)
			zombies[i].setName(name);
		return (zombies);
	}
	catch (std::bad_alloc &e)
	{
		std::cerr <<e.what() << std::endl;
		return(nullptr);
	}
}