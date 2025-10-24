
#include <iostream>
#include "PmergeMe.hpp"

int main(int argc, char **argv){
    if (argc == 1){
        std::cerr<<"Error\nno numbers, EX:./PmergeMe 3 5 9 7 4"<<std::endl;
    }
    PmergeMe data;
    try{
        data.run(argc, argv);
    }catch (const std::exception &e){
        std::cerr<<e.what()<<std::endl;
    }
    return (0);
}