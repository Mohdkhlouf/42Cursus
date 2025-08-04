#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void copy_test()
{
	std::cout << std::endl << "#####DEEP COPY TEST#####"<<std::endl;

	Dog dog1;
	Dog dog2(dog1);

	std::cout << std::endl << "IDEAS (before change) " << std::endl;
	std::cout << "Dog1 IDEA: " << dog1.getIdea(0) << std::endl;
	std::cout << "Dog2 IDEA: " << dog2.getIdea(0) << std::endl;

	dog1.setIdea(0, "new idea 1");
	dog2.setIdea(0, "new idea 2");

	std::cout << std::endl << "IDEAS (after change) " << std::endl;
	std::cout << "Dog1 IDEA: " << dog1.getIdea(0) << std::endl;
	std::cout << "Dog2 IDEA: " << dog2.getIdea(0) << std::endl;
	std::cout << std::endl;
}
void arr_test()
{
// animal array
std::cout<<"\nAnimal array test"<<std::endl;
Animal* animals[10];
for (int i = 0; i < 10; i++)
{

	if(i <5)
		animals[i] = new Dog();
	if (i >= 5 && i <10)
		animals[i] = new Cat();
}

for (int i = 0; i < 10; i++)
	{
		animals[i]->makeSound();
	}

for (int j = 0; j < 10; j++)
	{
		delete animals[j];
	}
}

void defualt_test()
{
const Animal* j = new Dog();
const Animal* i = new Cat();

delete j;
delete i;


Animal* a = new Dog();
a->makeSound(); // Outputs "Woof!"
delete a;


// Animal b; //this will not work because it is an abstract class.

}
int main()
{
	defualt_test();
	arr_test();
	copy_test();
return (0);
}