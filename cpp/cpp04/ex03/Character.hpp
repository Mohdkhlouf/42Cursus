#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"


class Character : public ICharacter{
	private:
		AMateria * inventory_[4];
		std::string name_;

	public:
		Character();
		Character(std::string name);
		~Character() override;
		Character(const Character &obj);
		Character& operator=(const Character& obj);

		std::string const & getName() const override;
		void equip(AMateria* m) override;
		void unequip(int idx) override;
		void use(int idx, ICharacter& target) override;
};

#endif