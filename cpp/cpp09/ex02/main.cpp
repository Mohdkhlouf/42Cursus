
#include <iostream>
#include "PmergeMe.hpp"

int main(int argc, char **argv){
    if (argc == 1){
        std::cerr<<"Error\nno numbers, EX:./PmergeMe 3 5 9 7 4"<<std::endl;
    }
    PmergeMe sort;
    sort.fillVector(argc, argv);
    sort.fillDeque(argc, argv);



    return (0);
}