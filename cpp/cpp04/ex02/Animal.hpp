#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <bits/stdc++.h>
#include <iostream>

class Animal
{
	private:
		std::string type;
		
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal &obj);
		Animal & operator=(const Animal &obj);
		virtual ~Animal();
		virtual void makeSound() const = 0;
		std::string getType() const;
};

#endif