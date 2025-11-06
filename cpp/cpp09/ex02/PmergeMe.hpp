#pragma once
#include <vector>
#include <deque>
#include <set>
#include <iostream>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <type_traits>

#define DEBUG false
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
    std::vector<int> intVector_orginal;
    std::deque<int> intDeque;
    std::deque<int> intDeque_orginal;

public:
    static int globalCounter;
    PmergeMe() = default;
    ~PmergeMe() = default;
    PmergeMe(const PmergeMe &obj) = default;
    PmergeMe &operator=(const PmergeMe &obj) = default;
    void fillVector(int argc, char **argv);
    void fillDeque(int argc, char **argv);
    void run(int argc, char **argv);
    bool hasDuplicates(std::vector<int> v);

    template <typename T>
    T findJacobsthalOrder(size_t pendsize)
    {
        T jacobOrder;
        if (pendsize == 0)
            return (jacobOrder);

        size_t j0 = 0; // Jacob - 2 (J(0))
        size_t j1 = 1; // Jacob - 1 (J(1))
        size_t prevJacob = 0;

        while (prevJacob < pendsize)
        {
            size_t currJacob = j1;

            if (currJacob == 1)
            {
                size_t nextJacob = j1 + (2 * j0);
                j0 = j1;
                j1 = nextJacob;
                continue;
            }

            size_t topJacob = currJacob;
            if (currJacob > pendsize)
                topJacob = pendsize;
            for (size_t i = topJacob; i > prevJacob; i--)
                jacobOrder.push_back(i);
            prevJacob = currJacob;
            size_t nextJacob = j1 + (2 * j0);
            j0 = j1;
            j1 = nextJacob;
        }
        return (jacobOrder);
    }

    template <typename T>
    std::string printData(T &container)
    {
        std::ostringstream oss;
        for (auto it = container.begin(); it != container.end(); it++)
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
            PmergeMe::globalCounter++;
            std::swap(container[firstPairStart + i], container[secondPairStart + i]);
        }
    }
    template <typename T>
    void sortData(T &container, size_t *level)
    {
        if (*level == 0 || container.size() < 2)
            return;

        size_t numPairs = container.size() / *level;
        if (numPairs < 2)
        {
            *level = *level / 2;
            return;
        }

        bool isOdd = (numPairs % 2 != 0);
        size_t end = (isOdd) ? container.size() - (*level * 2) + 1 : container.size();

        for (size_t i = 0; i < end; i += (2 * *level))
        {
            size_t firstIndex = i + *level - 1;
            size_t secondIndex = i + (*level * 2) - 1;

            // Clamp indices to container size
            if (firstIndex >= container.size())
                firstIndex = container.size() - 1;
            if (secondIndex >= container.size())
                secondIndex = container.size() - 1;

            if (container[firstIndex] > container[secondIndex])
            {
                swap(container, firstIndex, secondIndex, level);
            }
        }

        DEBUG_LOG("Level " << *level << ": " << printData(container));

        *level = *level * 2;
        sortData(container, level);
    }

    template <typename T>
    bool isSorted(const T &container)
    {
        return std::is_sorted(container.begin(), container.end());
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
    size_t whereToAdd(const T &main, const T &pendValue, size_t level)
    {
        if (main.empty())
            return 0;
        size_t pendSize = pendValue.size();
        int targetValue = pendValue[pendSize - 1]; // last element safely

        size_t left = 0;
        size_t right = main.size() / level;

        while (left < right)
        {
            size_t mid = left + (right - left) / 2; // Middle group
            size_t midStart = mid * level;
            size_t midEnd = std::min(midStart + level, main.size()); // avoid overflow
            int midValue = main[midEnd - 1];
            if (targetValue < midValue)
                right = mid; // Search left half
            else
                left = mid + 1; // Search right half
        }
        return left * level; // Convert to element position
    }

    // this function will return the value will be added from the pend vector.
    template <typename T>
    T whatToAdd(T &pend, int level, int index)
    {
        T temp;
        size_t startIndex = index * level;
        size_t endIndex = std::min(startIndex + level, pend.size()); // to protect from overflow

        temp.insert(temp.begin(), pend.begin() + startIndex, pend.begin() + endIndex);
        DEBUG_LOG("what to add:" << printData(temp));
        return (temp);
    }

    template <typename T>
    bool is_JacobsTahl(T jacobsThalNumbers, size_t e)
    {
        for (size_t it : jacobsThalNumbers)
        {
            if (it == e)
                return (true);
        }
        return false;
    }

    template <typename T>
    void binaryInsertion(T &main, T &pend, size_t level)
    {
        size_t position = 0;
        size_t counter = pend.size() / level;
        T pendValue;
        T addingOrder = findJacobsthalOrder<T>(counter);
        DEBUG_LOG("addingOrder:" << printData(addingOrder));

        for (size_t j : addingOrder)
        {
            pendValue = whatToAdd(pend, level, j - 1);
            position = whereToAdd(main, pendValue, level);
            main.insert(main.begin() + position, pendValue.begin(), pendValue.end());
            PmergeMe::globalCounter++;
        }
    }

    template <typename T>
    void jacobsThal(T &container, size_t *level)
    {
        if (*level < 1)
            return;
        DEBUG_LOG("\n"
                  << "I am JacobsThal!" << " LEVEL is: " << *level << "\nOriginal:" << printData(container));
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

        if (!pend.empty())
            binaryInsertion(main, pend, *level);
        main.insert(main.end(), leftNumbers.begin(), leftNumbers.end());

        DEBUG_LOG("Main:" << printData(main));
        DEBUG_LOG("Pend:" << printData(pend));
        DEBUG_LOG("leftNumbers:" << printData(leftNumbers));

        *level = *level / 2;
        jacobsThal(main, level);
        container = main;
    }
};
