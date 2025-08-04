#include "Cure.hpp"
#include "AMateria.hpp"

Cure::Cure():AMateria("Cure")
{}
Cure::Cure(const Cure &obj):AMateria(obj)
{
}

Cure& Cure::operator=(const Cure &obj)
{
	if(this != &obj){
		AMateria::operator=(obj);
	}
	return (*this);
}
Cure::~Cure(){

}

void AMateria::use(ICharacter& target){
	std::cout<<"* heals "<<target.getName()<<"'s wounds *"<<std::endl;
}

AMateria* AMateria::clone() const{
	return (new Cure());
}