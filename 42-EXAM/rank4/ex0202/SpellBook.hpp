#pragma once
#include <map>
#include <string>
#include "ASpell.hpp"


class SpellBook{
	private:
		std::map<std::string, ASpell*> spellMap;
	public:
		SpellBook();
		~SpellBook();
		SpellBook(const SpellBook &obj) =delete;
		SpellBook& operator=(const SpellBook &obj) = delete;
		void learnSpell(ASpell* spell);
		void forgetSpell(std::string const &sellName);
		ASpell* createSpell(std::string const &spellName);

};