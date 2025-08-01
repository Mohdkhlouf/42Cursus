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

for (int i = 0; i < 100; i++)
	{
		delete animals[i];
	}
{
	const Animal* j = new Dog();
	const Animal* i = new Dog();
	
	j = i;
	
	delete j;//should not create a leak
}



return (0);
}