#include "Ice.hpp"
#include "AMateria.hpp"

Ice::Ice():AMateria("ice")
{}
Ice::Ice(const Ice &obj):AMateria(obj)
{
}

Ice& Ice::operator=(const Ice &obj)
{
	if(this != &obj){
		AMateria::operator=(obj);
	}
	return (*this);
}
Ice::~Ice(){

}

void AMateria::use(ICharacter& target){
	std::cout<<"* shoots an ice bolt at "<<target.getName()<<" *"<<std::endl;
}

AMateria* AMateria::clone() const{
	return (new Ice());
}