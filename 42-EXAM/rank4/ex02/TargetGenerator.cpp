#include "TargetGenerator.hpp"

		TargetGenerator::TargetGenerator(){}
		TargetGenerator::~TargetGenerator(){
			targetbook.clear();
		}

		void TargetGenerator::learnTargetType(ATarget* target){
			if(target != nullptr ){
				std::map<std::string, ATarget*>::iterator it = targetbook.find(target->getType());
				if (it == targetbook.end())
					targetbook[target->getType()] = target;
			}
			
		}
		void TargetGenerator::forgetTargetType(std::string const &TargetType){
			std::map<std::string, ATarget*>::iterator it = targetbook.find(TargetType);
			if (it != targetbook.end()){
				targetbook.erase(it);
			}
		}
		ATarget* TargetGenerator::createTarget(std::string const &TargetType){
			std::map<std::string, ATarget*>::iterator it = targetbook.find(TargetType);
			if (it != targetbook.end()){
				return (it->second);
			}
			return(nullptr);
		}