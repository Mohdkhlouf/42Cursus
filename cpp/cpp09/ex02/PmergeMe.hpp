#pragma once
#include <vector>
#include <deque>
#include <iostream>
#include <cmath>
class PmergeMe
{
private:
    std::vector<int> intVector;
    std::deque<int> intDeque;

public:
    PmergeMe() = default;
    ~PmergeMe() = default;
    PmergeMe(const PmergeMe &obj) = default;
    PmergeMe &operator=(const PmergeMe &obj) = default;
    void fillVector(int argc, char **argv);
    void fillDeque(int argc, char **argv);

    void run(int argc, char **argv);
    template <typename T>
    void printDate(T &container)
    {
        typename T::iterator it;
        for (it = container.begin(); it != container.end(); it++)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    template <typename T>
    void sortData(T &container, size_t level)
    {
        std::cout << "LeveL: " << level << std::endl;
        if (container.size() < 2)
            return;
        if (container.size() / level < 2)
            return;
        bool is_odd = (container.size() / level) % 2;
        // typename T::iterator itb = container.begin();
        // typename T::iterator ite = (is_odd) ? std::prev(container.end()) : container.end();

        // for(auto it =itb + level;it != ite; it+=(level *2)){
        //     auto first = (it);
        //     auto second = (it+level*2);
        //     if (*first > *second){
        //         auto temp = *first;
        //         *first = *second;
        //         *second= temp;
        //     }

        size_t end = (is_odd) ? container.size() - 1 : container.size();
        for (size_t i = 0; i < end; i += static_cast<size_t>(std::pow(2, level)))
        {
            if (container[(i + level) - 1] > container[i + (level * 2) - 1])
            {
                swap(container, ((i + level) - 1), (i + (level * 2) - 1), level);
            }
        }
        // printDate(container);
        sortData(intVector, level *2);
    }

    template <typename T>
    void swap(T &container, size_t firstPairEnd, size_t secondPairEnd, size_t level)
    {
        size_t firstPairStart = firstPairEnd - level + 1;
        size_t secondPairStart = secondPairEnd - level + 1;
        for (size_t i = 0; i < level; ++i)
        {
            std::swap(container[firstPairStart + i], container[secondPairStart + i]);
        }
        printDate(container);
        // auto temp = container[firstPairEnd];
        // container[firstPairEnd] = container[seconPairEnd];
        // container[seconPairEnd] = temp;
    }
};