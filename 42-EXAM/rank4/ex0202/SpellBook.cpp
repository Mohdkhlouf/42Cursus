#include "SpellBook.hpp"

SpellBook::SpellBook() {}
SpellBook::~SpellBook() {
	spellMap.clear();
}

void SpellBook::learnSpell(ASpell *spell)
{
	if (spell != nullptr)
	{
		std::map<std::string, ASpell *>::iterator it = spellMap.find(spell->getName());
		if (it == spellMap.end())
		{
			spellMap[spell->getName()] = spell->clone();
		}
	}
}
void SpellBook::forgetSpell(std::string const &spellName)
{
	std::map<std::string, ASpell *>::iterator it = spellMap.find(spellName);
	if (it != spellMap.end())
	{
		delete it->second;
		spellMap.erase(spellName);
	}
}
ASpell *SpellBook::createSpell(std::string const &spellName)
{
	std::map<std::string, ASpell *>::iterator it = spellMap.find(spellName);
	if (it != spellMap.end())
	{
		return (it->second->clone());
	}
	return (nullptr);
}