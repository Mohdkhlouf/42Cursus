#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		std::string type;
		Brain *BrainPtr;

	public:
	Dog();
	Dog(std::string type);
	Dog(const Dog &obj);
	Dog& operator=(const Dog& dog);
	~Dog() override;
	void makeSound() const override;
	std::string getType();
};

#endif