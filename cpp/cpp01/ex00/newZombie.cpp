#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
	try
	{
		Zombie *ptr = new Zombie(name);
		return (ptr);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (nullptr);
	}
}