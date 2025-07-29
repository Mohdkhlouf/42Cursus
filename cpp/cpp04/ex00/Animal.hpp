#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	private:
		std::string type;
		
	public:
		Animal();
		Animal(std::string type);
		Animal(Animal &obj);
		Animal & operator=(Animal &obj);
		~Animal();
		void makeSound() const;
		std::string getType() const;
};

#endif