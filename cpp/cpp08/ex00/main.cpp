#include "easyfind.hpp"
#include <vector>
#include <queue>
#include <list>
#include <array>
#include <stack>

void vector_test()
{
    {
        std::cout << "\nInt Vector case 1\n";
        const std::vector<int> int_vec = {1, 2, 3, 4, 5, 6};
        std::cout << "result: " << std::distance(int_vec.begin(),easyfind(int_vec, 5)) << std::endl;
        // int_vec.push_back(10);
        std::cout << "result: " << std::distance(int_vec.begin(),easyfind(int_vec, 4)) << std::endl;
    }

    {
        std::cout << "\nChar Vector case 2\n";
        std::vector<char> char_vec = {'a', 'b', 'c'};
        std::cout << "Vector members:{";
        for (char c : char_vec)
        {
            std::cout << "'" << c << "'";
        }
        std::cout << "}\n";
         std::cout << "result wne (b): " << std::distance(char_vec.begin(), easyfind(char_vec, 'b')) <<std::endl;
        char_vec.push_back('d');
         std::cout << "result wne (d): " << std::distance(char_vec.begin(), easyfind(char_vec, 'd')) <<std::endl;
    }

    {
        std::cout << "\nChar Vector case 3\n";
        const std::vector<char> char_vec = {'a', 'b', 'c', 'd'};
        std::cout << "Vector members:{";
        for (char c : char_vec)
        {
            std::cout << "'" << c << "'";
        }
        std::cout << "}\n";
         std::cout << "position wne (d): " << std::distance(char_vec.begin(), easyfind(char_vec, 'b')) <<std::endl;
        std::cout << "position wne (d): " << std::distance(char_vec.begin(), easyfind(char_vec, 'd')) <<std::endl;
    }
}

void list_test()
{
    std::cout << "\nLIST Case\n";
    std::list<int> int_list = {1, 2, 3, 4, 5};

    std::cout << "List members:{";
    for (std::list<int>::iterator it = int_list.begin(); it != int_list.end(); it++)
    {
        std::cout << *it;
    }

    std::cout << "}\n";
    std::cout << "position when (b): " << std::distance(int_list.begin(), easyfind(int_list, 2))  << std::endl;
    std::cout << "position when (b): " << std::distance(int_list.begin(), easyfind(int_list, 5))  << std::endl;
}

void deque_test()
{
    std::cout << "\nDeque Case\n";
    std::deque<int> d;
    d.push_back(10);
    d.push_front(-10);
    d.push_back(20);
    d.push_back(30);
    d.push_front(-20);
    std::cout << "Position of 30 is:" << std::distance(d.begin(), easyfind(d, 30))  << std::endl;
}

void array_test()
{
    std::cout << "\nArray Case\n";
    std::array<int, 4> arr_int = {1, 2, 3, 4};
    std::cout << "position when 2: " << std::distance(arr_int.begin(), easyfind(arr_int, 2)) << std::endl;
    std::cout << "position when 2: " << std::distance(arr_int.begin(), easyfind(arr_int, 9)) << std::endl;
}

int main()
{
    try
    {
        vector_test();
    }
    catch (const value_not_found &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try
    {
        array_test();
    }
    catch (const value_not_found &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try
    {
        deque_test();
    }
    catch (const value_not_found &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try
    {
        list_test();
    }
    catch (const value_not_found &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return (0);
}
