#pragma once
#include <map>
#include <string>
#include "ATarget.hpp"


class TargetGenerator{
	private:
		std::map<std::string, ATarget*> targetMap;
	public:
		TargetGenerator();
		~TargetGenerator();
		TargetGenerator(const TargetGenerator &obj) =delete;
		TargetGenerator& operator=(const TargetGenerator &obj) = delete;
		void learnTargetType(ATarget* target);
		void forgetTargetType(std::string const &sellName);
		ATarget* createTarget(std::string const &targetName);

};