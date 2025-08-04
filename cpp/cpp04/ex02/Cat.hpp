#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain* brain;

	public:
		Cat();
		Cat(const Cat &obj);
		Cat& operator=(const Cat &obj);
		~Cat() override;
		void makeSound() const override;
		std::string getIdea(unsigned int index);
		void setIdea(unsigned int index, std::string idea);
};

#endif