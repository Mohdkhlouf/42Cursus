#include "ASpell.hpp"


ASpell::ASpell(const std::string &name, const std::string &effects):name_(name), effects_(effects){}
ASpell::~ASpell(){}
std::string ASpell::getName() const{
	return name_;
}
std::string ASpell::getEffects() const{
	return effects_;
}

void ASpell::launch(const ATarget &target) const{
	target.getHitBySpell(*this);
}