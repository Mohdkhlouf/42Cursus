#pragma once
#include <string>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <map>

class Warlock{
	private:
		std::string name_;
		std::string title_;
		std::map<std::string, ASpell*> spellsMap;
	public:
		Warlock() = delete;
		~Warlock();
		Warlock(const Warlock &obj) = delete;
		Warlock& operator=(const Warlock &obj) = delete;
		Warlock(const std::string &name, const std::string &title);
		std::string getName() const;
		std::string getTitle() const;
		void setTitle(const std::string &title);
		void introduce() const;

		void learnSpell(const ASpell * spell);
		void forgetSpell(const std::string &spellName);
		void launchSpell(const std::string &spellName, const ATarget &target);

};