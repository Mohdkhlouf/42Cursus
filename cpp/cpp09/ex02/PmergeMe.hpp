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
            bool is_odd = (container.size() / level )%2;
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
            for (size_t i = level - 1 ; i < end; i+=level*2){
                std::cout<<"debug:"<<container[i]<<" Debug2:"<<container[i + (level*2)-1]<<std::endl;
                if (container[i] > container[i + (level*2)-1]){
                    auto temp = container[i];
                    container[i] = container[i + (level*2)-1];
                    container[i + (level*2)-1] = temp;
                }
                std::cout<<"debug:"<<i<<std::endl;
                // std::cout<<"DEbig:"<<i+(level * 2)<<std::endl;

            }
            printDate(container);
        }

};