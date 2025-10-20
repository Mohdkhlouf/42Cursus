
#include "RPN.hpp"
#include <iostream>


int main(int argc, char **argv){
    if (argc != 2){
        std::cerr<<"Error\nCheck your arguments please!"<<std::endl;
        return (1);
    }
    RPN stack;
    stack.calculate(argv[1]);
    return (0);
}
