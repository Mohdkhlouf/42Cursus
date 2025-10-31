#pragma once
#include <vector>
#include <deque>
#include <iostream>
#include <cmath>
#include <sstream>

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
        typename T::iterator it;
        std::ostringstream oss;
        for (it = container.begin(); it != container.end(); it++)
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


    template <typename T>
    size_t whereToAdd(const T &main, const T &PendMember, size_t level)
    {
        (void) PendMember;
        (void) main;
        (void) level;
        // std::cout << "select whereToAdd.";
        return (0);
    }


    template <typename T>
    void binaryInsertion(T &main, T &pend, T &leftNumbers, size_t level)
    {
        (void)leftNumbers;
        std::vector<size_t> jacobsThalNumbers = {1,3,5,11, 21,43,85,171,341,683,1365};
        size_t counter = pend.size() / level;
        
        for (size_t e = jacobsThalNumbers.begin() ; e < counter; e++){
            
            // size_t position = whereToAdd(main, pendValue(pend), level);
            size_t position = main.end();
            main.insert(main.begin() + position , pendValue(pend).begin(), pendValue(pend).end());
        }
    }

    template <typename T>
    void jacobsThal(T &container, size_t *level)
    {
        if (*level < 1)
            return;
        DEBUG_LOG("\n"
                  << "I am JacobsThal!" << *level << " container is: " << printDate(container));
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
            DEBUG_LOG("it is odd, and there are " << counter << " numbers will be moved to the nonearticipating container");
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
            DEBUG_LOG("Pend is empty, so all felt will pushed to main");
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

        jacobsThal(container, level);
    }
};