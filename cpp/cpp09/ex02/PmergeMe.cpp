#include "PmergeMe.hpp"
#include <iostream>

void PmergeMe::fillVector(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        int toBeAdded = std::stoi(argv[i]);
        if (toBeAdded >= 0)
            intVector.push_back(toBeAdded);
        else
            throw std::runtime_error("Error\ninvalid inputs");
    }
}

void PmergeMe::fillDeque(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        intDeque.push_back(std::stoi(argv[i]));
    }
    std::cout << intDeque.front() << " | " << intDeque.back() << std::endl;
}

void PmergeMe::run(int argc, char **argv){
    fillVector(argc, argv);
    // fillDeque(argc, argv);
    sortData(intVector, 1);
    // sortData(intDeque, 1);
}