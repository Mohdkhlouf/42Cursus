
#include "RPN.hpp"
#include <iostream>


int main(int argc, char **argv){
    if (argc != 2){
        std::cerr<<"Error\nCheck your arguments please!"<<std::endl;
        return (1);
    }
    RPN stack;
    try{
        stack.calculate(argv[1]);
    }catch (const std::exception &e){
        std::cerr<<e.what()<<std::endl;
    }
    
    return (0);
}
