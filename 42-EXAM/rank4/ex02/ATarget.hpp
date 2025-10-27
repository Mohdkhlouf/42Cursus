#pragma once
#include <string>
#include "ASpell.hpp"

class ASpell;
class ATarget{
	protected:
		std::string type_;

	public:
		virtual ~ATarget();
		ATarget(const std::string &type);
		std::string getType() const;
		virtual ATarget *clone() const = 0;
		void getHitBySpell(const ASpell &spell)const;
};