#include "SpellBook.hpp"

		SpellBook::SpellBook(){}
		SpellBook::~SpellBook(){
			spellbook.clear();
		}
		void SpellBook::learnSpell(ASpell*spell){
			if(spell != nullptr ){
				std::map<std::string, ASpell*>::iterator it = spellbook.find(spell->getName());
				if (it == spellbook.end())
					spellbook[spell->getName()] = spell;
			}
			
		}
		void SpellBook::forgetSpell(std::string const &spellName){
			std::map<std::string, ASpell*>::iterator it = spellbook.find(spellName);
			if (it != spellbook.end()){
				spellbook.erase(it);
			}
		}
		ASpell* SpellBook::createSpell(std::string const &spellName){
			std::map<std::string, ASpell*>::iterator it = spellbook.find(spellName);
			if (it != spellbook.end()){
				return (it->second->clone());
			}
			return(nullptr);
		}