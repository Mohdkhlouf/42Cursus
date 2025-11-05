#include "PmergeMe.hpp"
#include <iostream>


bool PmergeMe::hasDuplicates(std::vector<int> v) { // pass by value so we can sort
    std::sort(v.begin(), v.end());
    return std::adjacent_find(v.begin(), v.end()) != v.end();
}


void PmergeMe::fillVector(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        int toBeAdded = std::stoi(argv[i]);
        if (toBeAdded >= 0){
            intVector.push_back(toBeAdded);
        }
        else
            throw std::runtime_error("Error\ninvalid inputs");
    }
    std::vector<int> temp;
    temp = intVector;
    if (hasDuplicates(temp)){
        std::cerr<<"Error\nthere is duplicates. fix it please";
        exit(1);
    }
    intVector_orginal  = intVector;
}

void PmergeMe::fillDeque(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        intDeque.push_back(std::stoi(argv[i]));
    }
    intDeque_orginal = intDeque;
}


void PmergeMe::run(int argc, char **argv){
    
    {
        size_t level = 1;
        fillVector(argc, argv);
        std::cout<<"Before: "<<printData(intVector_orginal);
        sortData(intVector, &level);
        jacobsThal(intVector, &level);
        std::cout<<"\nAfter : "<<printData(intVector);
    }
   
    {
        size_t level = 1;
        fillDeque(argc, argv);
        std::cout<<"\nBefore: "<<printData(intDeque_orginal);
        sortData(intDeque, &level);
        jacobsThal(intDeque, &level);
        std::cout<<"\nAfter : "<<printData(intDeque);
    }
}