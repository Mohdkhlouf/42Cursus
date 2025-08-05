#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria * materiaInventory_[4];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource &obj);
		MateriaSource& operator=(const MateriaSource &obj);
		~MateriaSource();

		void learnMateria(AMateria*) override;
		AMateria* createMateria(std::string const & type) override;
};

#endif