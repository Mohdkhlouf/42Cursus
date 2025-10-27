#include "Fwoosh.hpp"

Fwoosh::Fwoosh():ASpell("Fwoosh", "Fwooshed"){}

ASpell *Fwoosh::clone() const{
	return (new Fwoosh);
};
