#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
class Zombie{

	private:
		std::string name;

	public:
		void setName(std::string name);
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void announce( void );
};

Zombie* zombieHorde( int N, std::string name );

#endif