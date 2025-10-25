#pragma once
#include <vector>
#include <deque>
#include <iostream>
#include <cmath>
#include <sstream>

#define DEBUG true

#if DEBUG
    #define DEBUG_LOG(x) do { std::cout << x << std::endl; } while(0)
#else
    #define DEBUG_LOG(x) do {} while(0)
#endif

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
    std::string printDate(T &container)
    {
        typename T::iterator it;
        std::ostringstream oss;
        for (it = container.begin(); it != container.end(); it++)
        {
            oss<<*it<<" ";
        }
        return (oss.str());
    }

    template <typename T>
    void sortData(T &container, size_t level)
    {

        if (container.size() < 2)
            return;
        if (container.size() / level < 2)
            return;
        bool is_odd = (container.size() / level) % 2;
        size_t end = (is_odd) ? container.size() - 1 : container.size();
        for (size_t i = 0; i < end; i += static_cast<size_t>(std::pow(2, level)))
        {
            if (container[(i + level) - 1] > container[i + (level * 2) - 1])
            {
                swap(container, ((i + level) - 1), (i + (level * 2) - 1), level);
            }
        }
        DEBUG_LOG("LeveL " << level<<": "<<printDate(intVector));
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
    }
};