#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* j = new Dog();
const Animal* i = new Cat();

delete j;//should not create a leak
delete i;


// animal array
std::cout<<"\nAnimal array test"<<std::endl;
Animal* animals[100];
for (int i = 0; i < 100; i++)
{
	if(i <50)
		animals[i] = new Dog();
	if (i >= 50 && i <100)
		animals[i] = new Cat();
}

for (int i = 0; i < 100; i++)
	{
		animals[i]->makeSound();
	}

for (int j = 0; j < 100; j++)
	{
		delete animals[j];
	}
return (0);
}