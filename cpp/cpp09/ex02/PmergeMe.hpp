#pragma once
#include <vector>
#include <deque>

class PmergeMe{
    private:
        std::vector<int> intVector;
        std::deque<int> intDeque;

    public:
        PmergeMe() = default;
        ~PmergeMe() = default;
        PmergeMe(const PmergeMe &obj) = default;
        PmergeMe & operator=(const PmergeMe &obj) = default;
        void fillVector(int argc, char **argv);
        void fillDeque(int argc, char **argv);

};