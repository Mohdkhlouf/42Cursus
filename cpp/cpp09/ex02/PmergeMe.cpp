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
    std::cout << intVector.front() << " | " << intVector.back() << std::endl;
}

void PmergeMe::fillDeque(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        intDeque.push_back(std::stoi(argv[i]));
    }
    std::cout << intDeque.front() << " | " << intDeque.back() << std::endl;
}

void PmergeMe::print_pairVector()
{
    for (auto it = pairVector.begin(); it != pairVector.end(); it++)
    {
        std::cout << "(" << (*it).num1 << "," << (*it).num2 << ")" << std::endl;
    }
}
void PmergeMe::sortVector()
{

    for (auto it = intVector.begin(); it != intVector.end(); it++)
    {
        t_pair pair;
        pair.num1 = *it;
        pair.num2 = *(it + 1);
        it++;
        pairVector.push_back(pair);
    }
    print_pairVector();
}