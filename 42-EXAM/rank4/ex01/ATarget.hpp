#pragma once
#include <string>
#include "ASpell.hpp"


class ATarget{
	protected:
		std::string type_;

	public:
		~ATarget();
		ATarget(const std::string &type);
		std::string getType() const;
		virtual ATarget *clone() const = 0;
		void getHitBySpell(const ASpell &spell)const;
};