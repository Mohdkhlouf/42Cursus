#pragma once
#include <map>
#include <string>
#include "ATarget.hpp"


class TargetGenerator{
	private:
		std::map<std::string, ATarget*> targetbook;

	public:
		TargetGenerator();
		~TargetGenerator();
		void learnTargetType(ATarget*);
		void forgetTargetType(std::string const &);
		ATarget* createTarget(std::string const &);
};