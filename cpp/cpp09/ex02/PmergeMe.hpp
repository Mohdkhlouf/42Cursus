#pragma once
#include <vector>
#include <deque>
#include <iostream>
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

        void run(int argc, char **argv);
        template <typename T>
        void printDate(T &container){
            typename T::iterator it;
            for (it = container.begin(); it != container.end(); it++){
                std::cout<<*it<<" ";
            }
            std::cout<<std::endl;
        }
        template <typename T>
        void sortData(T &container, size_t level){
            if (container.size() < 2)
                return;
            bool is_odd = container.size()%2;
            (void) level;
            typename T::iterator itb = container.begin();
            typename T::iterator ite = (is_odd) ? std::prev(container.end()) : container.end();

            for(auto it =itb;it != ite; it++){
                if (*it > *(it+1)){
                    auto temp = *it;
                    *it = *(it+1);
                    *(it+1) = temp;
                }
                it++;
            }
            printDate(container);
        }

};