#pragma once
#include <string>
#include "ATarget.hpp"

class ATarget;
class ASpell{
	protected:
		std::string name_;
		std::string effects_;
	public:
		virtual ~ASpell();
		ASpell(const std::string &name, const std::string &effects);
		std::string getName() const;
		std::string getEffects() const;
		virtual ASpell *clone() const = 0;
		void launch(const ATarget &target) const;
};