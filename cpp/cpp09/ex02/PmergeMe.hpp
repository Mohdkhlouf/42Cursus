#pragma once
#include <vector>
#include <deque>


typedef struct s_pair{
    int num1;
    int num2;
}t_pair;



class PmergeMe{
    private:
        std::vector<int> intVector;
        std::deque<int> intDeque;
        std::vector<t_pair> pairVector;
        std::deque<t_pair> pairDeque;

    public:
        PmergeMe() = default;
        ~PmergeMe() = default;
        PmergeMe(const PmergeMe &obj) = default;
        PmergeMe & operator=(const PmergeMe &obj) = default;
        void fillVector(int argc, char **argv);
        void fillDeque(int argc, char **argv);
        void sortVector();
        void sortDeque();
        void print_pairVector();
};