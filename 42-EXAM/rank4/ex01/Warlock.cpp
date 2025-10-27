#include "Warlock.hpp"
#include <iostream>

Warlock::Warlock(const std::string &name, const std::string &title):name_(name),title_(title){
	std::cout<<name_<<": This looks like another boring day."<<std::endl;
}
Warlock::~Warlock(){
	std::cout<<name_<<": My job here is done!"<<std::endl;
	for(auto it = spellsMap.begin(); it != spellsMap.end(); it++){
		delete it->second;
	}
	spellsMap.clear();
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

void Warlock::learnSpell(const ASpell * spell){
	if(spell){
		std::map<std::string, ASpell*>::iterator it = spellsMap.find(spell->getName());
		if (it == spellsMap.end()){
			spellsMap[spell->getName()] = spell->clone();
		}
	}
}

void Warlock::forgetSpell(const std::string &spellName){
	std::map<std::string, ASpell*>::iterator it = spellsMap.find(spellName);
	if (it != spellsMap.end()){
		delete it->second;
		spellsMap.erase(it->first);
	}
}

void Warlock::launchSpell(const std::string &spellName, const ATarget &target){
	std::map<std::string, ASpell*>::iterator it = spellsMap.find(spellName);
	if(it != spellsMap.end()){
		it->second->launch(target);
	}
}