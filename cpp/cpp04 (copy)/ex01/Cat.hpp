#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		std::string type;
		Brain *BrainPtr;

	public:
	Cat();
	Cat(std::string type);
	Cat(const Cat &obj);
	Cat& operator=(const Cat& cat);
	~Cat() override;
	void makeSound() const override;
	std::string getType();
};

#endif