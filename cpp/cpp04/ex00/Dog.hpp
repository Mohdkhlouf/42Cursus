#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	private:
		std::string type;

	public:
	Dog();
	Dog(std::string type);
	Dog(Dog &obj);
	Dog& operator=(Dog& dog);
	~Dog();
	void makeSound();
	std::string getType();
};

#endif