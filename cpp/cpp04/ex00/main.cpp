#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void test3()
{
	std::cout<<"##############Part3: WrongAnimal class Tests ##############"<<std::endl;
	std::cout<<"WrongAnimal Test"<<std::endl;
	WrongAnimal* wanimal = new WrongCat();
	wanimal->makeSound();
	delete wanimal;
	std::cout<<"##############Part1: Test ended. ##############"<<std::endl;
}
void test2()
{
std::cout<<"##############Part2: Create Animal objects pointers from each class Test##############"<<std::endl;
	const Animal test;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

		delete i;
	delete j;
	delete meta;
std::cout<<"##############Part2: Test ended. ##############"<<std::endl;


}

void test1()
{
	std::cout<<"##############Part1: Create objects from each class Test##############"<<std::endl;
	std::cout<<"##############Create object from Animal Class##############"<<std::endl;
	Animal x;
	std::cout<<x.getType()<<std::endl;
	x.makeSound();
	std::cout<<"##############Create object from Cat Class##############"<<std::endl;
	Cat cat;
	std::cout<<cat.getType()<<std::endl;
	cat.makeSound();
	std::cout<<"##############Create object from Dog Class##############"<<std::endl;
	Dog dog;
	std::cout<<dog.getType()<<std::endl;
	dog.makeSound();
	std::cout<<"##############Part1: Test ended. ##############"<<std::endl;

}
int main()
{
	test1();
	test2();
	test3();
	return (0);
}