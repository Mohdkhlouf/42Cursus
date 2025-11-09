#include "PmergeMe.hpp"
#include <iostream>
#include <chrono>

int PmergeMe::globalCounter = 0;

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
        std::cout<<"VECTOR CONTAINER:\nBefore: "<<printData(intVector_orginal);
        auto start = std::chrono::high_resolution_clock::now();
        sortData(intVector, &level);
        jacobsThal(intVector, &level);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout<<"\nAfter : "<<printData(intVector);
        if (isSorted(intVector)){
            std::cout << "\nSORT STATUS = SORTED CORRECTLY"<< std::endl;
        }else
        {
             std::cout << "\nSORT STATUS = FAILED"<< std::endl;
        }
        std::cout<<"Steps Counter is :"<<PmergeMe::globalCounter<<std::endl;
        std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;
    }
   
    {
        PmergeMe::globalCounter = 0;
        size_t level = 1;
        fillDeque(argc, argv);
        std::cout<<"\nDEQUE CONTAINER:\nBefore: "<<printData(intDeque_orginal);
        auto start = std::chrono::high_resolution_clock::now();
        sortData(intDeque, &level);
        jacobsThal(intDeque, &level);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout<<"\nAfter : "<<printData(intDeque);
        if (isSorted(intDeque)){
            std::cout << "\nSORT STATUS = SORTED CORRECTLY"<< std::endl;
        }else
        {
             std::cout << "\nSORT STATUS = FAILED"<< std::endl;
        }
        std::cout<<"Steps Counter is :"<<PmergeMe::globalCounter<<std::endl;
        std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;
    }
}