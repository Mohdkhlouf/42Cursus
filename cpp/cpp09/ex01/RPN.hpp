#pragma once
#include <stack>
#include <string>


class RPN{
    private:
        std::stack<int> rpnStack;
    public:
        RPN() = default;
        ~RPN() = default;
        RPN(const RPN&);
        RPN& operator=(const RPN&);
        bool calculate(const std::string &);

};
