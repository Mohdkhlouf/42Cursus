#pragma once
#include <stack>
#include <string>


class RPN{
    private:
        std::stack<int> rpnStack;
    public:
        RPN() = default;
        ~RPN() = default;
        RPN(const RPN&) = default;
        RPN& operator=(const RPN&) = default;

        bool calculate(const std::string &);
        bool checkValues(const std::string &numbers);
        bool isValidOperation(const char c);
        void print_stack();
        void transaction(char c, long long *result);

};
