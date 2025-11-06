
#include <iostream>
#include "PmergeMe.hpp"

int main(int argc, char **argv){
    if (argc == 1){
        std::cerr<<"Error\nno numbers, EX:./PmergeMe 3 5 9 7 4"<<std::endl;
        return (1);
    }
    PmergeMe data;
    try{
        data.run(argc, argv);
    }catch (const std::invalid_argument& e){
        std::cerr << "Error: invalid argument — not a number.\n";
        return (1);
    }catch (const std::exception &e){
        std::cerr<<e.what()<<std::endl;
        return (1);
    }
    return (0);
}