#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <iostream>
#include <bits/stdc++.h>

class Cat : public Animal
{
	private:
		std::string type;
	public:
	Cat();
	Cat(std::string type);
	Cat(const Cat &obj);
	Cat& operator=(const Cat &obj);
	~Cat();
	void makeSound() const override;
};

#endif