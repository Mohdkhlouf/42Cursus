#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}
TargetGenerator::~TargetGenerator() {
	targetMap.clear();
}

void TargetGenerator::learnTargetType(ATarget *target)
{
	if (target != nullptr)
	{
		std::map<std::string, ATarget *>::iterator it = targetMap.find(target->getType());
		if (it == targetMap.end())
		{
			targetMap[target->getType()] = target->clone();
		}
	}
}
void TargetGenerator::forgetTargetType(std::string const &targetName)
{
	std::map<std::string, ATarget *>::iterator it = targetMap.find(targetName);
	if (it != targetMap.end())
	{
		delete it->second;
		targetMap.erase(targetName);
	}
}
ATarget *TargetGenerator::createTarget(std::string const &targetName)
{
	std::map<std::string, ATarget *>::iterator it = targetMap.find(targetName);
	if (it != targetMap.end())
	{
		return (it->second->clone());
	}
	return (nullptr);
}