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
	Dog(const Dog &obj);
	Dog& operator=(const Dog& dog);
	~Dog();
	void makeSound() const override;

};

#endif