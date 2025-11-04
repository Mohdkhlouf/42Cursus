#pragma once
#include <vector>
#include <deque>
#include <iostream>
#include <cmath>
#include <sstream>
#include <algorithm> 

#define DEBUG true

#if DEBUG
#define DEBUG_LOG(x)                 \
    do                               \
    {                                \
        std::cout << x << std::endl; \
    } while (0)
#else
#define DEBUG_LOG(x) \
    do               \
    {                \
    } while (0)
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
        // typename T::iterator it;
        std::ostringstream oss;
        for ( auto it = container.begin(); it != container.end(); it++)
        {
            oss << *it << " ";
        }
        return (oss.str());
    }

    template <typename T>
    void swap(T &container, size_t firstPairEnd, size_t secondPairEnd, size_t *level)
    {
        size_t firstPairStart = firstPairEnd - *level + 1;
        size_t secondPairStart = secondPairEnd - *level + 1;
        for (size_t i = 0; i < *level; ++i)
        {
            std::swap(container[firstPairStart + i], container[secondPairStart + i]);
        }
    }

    template <typename T>
    void sortData(T &container, size_t *level)
    {
        if (container.size() < 2)
            return;
        if (container.size() / *level < 2)
        {
            *level = *level / 2;
            return;
        }

        bool is_odd = (container.size() / *level) % 2;
        size_t end = (is_odd) ? container.size() - (*level * 2) + 1 : container.size();
        for (size_t i = 0; i < end; i += (2 * *level))
        {
            if (container[(i + *level) - 1] > container[i + (*level * 2) - 1])
            {
                swap(container, ((i + *level) - 1), (i + (*level * 2) - 1), level);
            }
        }
        DEBUG_LOG("LeveL " << *level << ": " << printDate(container));
        *level = *level * 2;
        sortData(container, level);
    }

    template <typename T>
    void pushMain(T &main, T &container, size_t startPoint, size_t level)
    {
        for (size_t i = 0; i < level; i++)
        {
            main.push_back(container[startPoint + i]);
        }
    }

    template <typename T>
    void pushPend(T &pend, T &container, size_t startPoint, size_t level)
    {
        for (size_t i = 0; i < level; i++)
        {
            pend.push_back(container[startPoint + i]);
        }
    }

    ////this function will decide where to add the pend value by binary search.
    template <typename T>
    size_t whereToAdd(const T &main,const T &pendvalue, int e, size_t level, int last_position)
    {
        (void) last_position;
        (void) e;
        int pendPosition = pendvalue[level - 1];
        // int mainPosition = main[e*level -1 ];
        DEBUG_LOG("\n"<< "Main is:" << printDate(main));
        size_t counter = main.size() / level;
        for(size_t s = 1; s <= counter ; s++){
            if ( pendPosition < main[s*level -1 ]){
                return((s - 1)*level);
            }
        }
        return (counter);
    }

    //this function will return the value will be added from the pend vector.
    template <typename T>
    T whatToAdd(T &pend, int level, int index){
        T temp;
        size_t startIndex = index * level;
        size_t endIndex = startIndex + level;

        temp.insert(temp.begin(), pend.begin() + startIndex ,pend.begin() + endIndex);
        DEBUG_LOG("what to add:"<<printDate(temp));
        return (temp);
    }

    template <typename T>
    bool is_JacobsTahl(T jacobsThalNumbers, size_t e){
        for(size_t it: jacobsThalNumbers){
            if(it == e)
                return (true);
        }
        return false;
    }
    template <typename T>
    void binaryInsertion(T &main, T &pend, T &leftNumbers, size_t level)
    {
        DEBUG_LOG("Main in binaryInsertion:" << printDate(main));
        DEBUG_LOG("Pend in binaryInsertion:" << printDate(pend));
        DEBUG_LOG("leftNumbers in binaryInsertion:" << printDate(leftNumbers));
        (void)leftNumbers;
        (void)main;
        size_t position = 0;
        std::vector<size_t> jacobsThalNumbers = {1,3,5,11, 21,43,85,171,341,683,1365};
        size_t counter = pend.size() / level;
        (void) counter;
        T pendValue;
        //this will add the values from pend by jacobsthal numbers.


        for (size_t j = 1; j < jacobsThalNumbers.size() ; j++){
            size_t start = jacobsThalNumbers[j];
            size_t end = jacobsThalNumbers[j - 1];
            size_t step = start - end;

            std::cout <<"step is: "<<step<<std::endl;
                for(size_t k = start; k > end  ; k--){
                    if (k > counter)
                        continue;
                    pendValue = whatToAdd(pend, level, k-1);
                    position = whereToAdd(main, pendValue, k-1, level, position);
                    main.insert(main.begin() + position , pendValue.begin(), pendValue.end());
                }
                           
            if (jacobsThalNumbers[j] > counter)
                break;
            }
            pendValue = whatToAdd(pend, level, 0);
            position = whereToAdd(main, pend, 0, level, position);
            main.insert(main.begin() + position , pendValue.begin(), pendValue.end()); 
        }    

    template <typename T>
    void jacobsThal(T &container, size_t *level)
    {
        if (*level < 1)
            return;
        DEBUG_LOG("\n"<< "I am JacobsThal!" <<" LEVEL is: "<< *level );
        T main;
        T pend;
        T leftNumbers;
        T temp;
        size_t counter = 0;
        bool is_odd = (container.size() % *level);
        if (is_odd)
        {
            counter = container.size() % *level;
            for (size_t i = container.size() - counter; i < container.size(); i++)
            {
                leftNumbers.push_back(container[i]);
            }
        }
        size_t pairCounter = container.size() / *level;
        for (size_t e = 0; e < pairCounter; e++)
        {
            if (e == 0)
            {
                pushMain(main, container, e * (*level), *level);
            }
            else if (e % 2 != 0)
            {
                pushMain(main, container, e * (*level), *level);
            }
            else
            {
                pushPend(pend, container, e * (*level), *level);
            }
        }

        if (pend.empty())
        {
            DEBUG_LOG("Pend is empty, so all lefted numbers will pushed to main");
            pushMain(main, leftNumbers, 0, leftNumbers.size());
        }
        else
        {
            binaryInsertion(main, pend, leftNumbers, *level);
        }

        DEBUG_LOG("Main:" << printDate(main));
        DEBUG_LOG("Pend:" << printDate(pend));
        DEBUG_LOG("leftNumbers:" << printDate(leftNumbers));

        *level = *level / 2;

        jacobsThal(main, level);
    }
};