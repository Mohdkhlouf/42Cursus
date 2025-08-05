#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
	for(int i = 0; i < 4; i++){
		materiaInventory_[i] = nullptr;
	}
}

MateriaSource::MateriaSource(const MateriaSource &obj){
	for (int i = 0; i < 4; ++i)
		materiaInventory_[i] = nullptr;

	for (int i = 0; i < 4; ++i) {
		if (obj.materiaInventory_[i])
			materiaInventory_[i] = obj.materiaInventory_[i]->clone();
	}
}


MateriaSource& MateriaSource::operator=(const MateriaSource &obj){
	if(this != &obj)
	{
		for(int i = 0; i < 4; i++){
			if(materiaInventory_[i]){
				delete materiaInventory_[i];
				materiaInventory_[i] = nullptr;
			}
			if (obj.materiaInventory_[i])
				materiaInventory_[i] = obj.materiaInventory_[i]->clone();
			else
				materiaInventory_[i] = nullptr;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource(){
	for (int i = 0; i < 4; i++)
	{
		if (materiaInventory_[i]){
			delete materiaInventory_[i];
			materiaInventory_[i] = nullptr;
		}
	}
}

void MateriaSource::learnMateria(AMateria* m){
	if (!m){
		return;
	}
	for(int i = 0; i<4;i++){
		if(!materiaInventory_[i])
		{
			materiaInventory_[i] = m;
			return;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type){
	for (int i=0; i< 4 ; i++){
		if(materiaInventory_[i] && materiaInventory_[i]->getType() == type){
			return (materiaInventory_[i]->clone());
		}
	}
	return nullptr;
}