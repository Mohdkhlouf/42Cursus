#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	private:
		std::string type;
	public:
	Cat();
	Cat(std::string type);
	Cat(Cat &obj);
	Cat& operator=(Cat& cat);
	~Cat();
	void makeSound();
	std::string getType();
};

#endif