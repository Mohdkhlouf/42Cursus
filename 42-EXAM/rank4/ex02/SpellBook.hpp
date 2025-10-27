#pragma once
#include <map>
#include <string>
#include "ASpell.hpp"


class SpellBook{
	private:
		std::map<std::string, ASpell*> spellbook;

	public:
		SpellBook();
		~SpellBook();
		void learnSpell(ASpell*);
		void forgetSpell(std::string const &);
		ASpell* createSpell(std::string const &);
};