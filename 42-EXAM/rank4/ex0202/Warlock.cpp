#include "Warlock.hpp"
#include <iostream>

Warlock::Warlock(const std::string &name, const std::string &title):name_(name),title_(title){
	std::cout<<name_<<": This looks like another boring day."<<std::endl;
}
Warlock::~Warlock(){
	std::cout<<name_<<": My job here is done!"<<std::endl;
}
std::string Warlock::getName() const{
	return name_;
}
std::string Warlock::getTitle() const{
	return title_;
}
void Warlock::setTitle(const std::string &title){
	title_=title;
}

void Warlock::introduce() const{
	std::cout<<name_<<": I am "<<name_<<", "<<title_<<std::endl;
}

void Warlock::learnSpell(ASpell *spell){
	spellBook.learnSpell(spell);
}

void Warlock::forgetSpell(const std::string &spellName){
	spellBook.forgetSpell(spellName);
}

void Warlock::launchSpell(const std::string &spellName, const ATarget &target){
	ASpell *temp = spellBook.createSpell(spellName);
	if (temp != nullptr){
		temp->launch(target);
		delete temp;
	}
}