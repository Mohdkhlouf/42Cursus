#include "RPN.hpp"
#include <iostream>

bool isValidOperation(const char c){
    std::string operations ="+-*/";
    for(auto it:operations){
        if(c == it)
            return (true);
    }
    return false;
}

bool checkValues(const std::string &numbers){
    for (auto it:numbers){
        if (!std::isdigit(it) || !isValidOperation(it)){
            std::cerr<<"Error\nInvalid values!"<<std::endl;
            return false;
        }
        std::cout<<it<<std::endl;
    }
    return (true);
}


bool RPN::calculate(const std::string &numbers){
    if(!checkValues(numbers))
        return false;
    return true;
}
