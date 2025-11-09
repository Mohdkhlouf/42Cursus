#include "RPN.hpp"
#include <iostream>
#include <string> 
#include <stack>
#include <climits>

void RPN::print_stack(){
    std::stack<int> print = rpnStack;
    if(print.size() != 1)
        throw std::runtime_error("Error\nNot enough operands");

    while(!print.empty()){
        std::cout<<print.top()<<std::endl;
        print.pop();
    }
}


bool RPN::isValidOperation(const char c){
    std::string operations =" +-*/";
    for(auto it:operations){
        if(c == it){
            return (true);
        }    
    }
    return false;
}

bool RPN::checkValues(const std::string &numbers){
    for (auto it:numbers){
        if ((std::isdigit(it) == 0) && !isValidOperation(it)){
            std::cerr<<"Error\nInvalid values!"<<std::endl;
            return false;
        }
    }
    return (true);
}

void  RPN::transaction(char c, long long *result){
    if(rpnStack.size() < 2)
        throw std::runtime_error("invalid inputs");
    long long second = 0;
    long long first = 0;

    second = rpnStack.top();
    rpnStack.pop();
    first = rpnStack.top();
    rpnStack.pop();
    if (c == '+')
        *result = (first + second);
    else if (c == '-')
        *result = (first - second);
    else if (c == '*')
        *result =  (first * second);
    else if (c == '/'){
        if (second == 0)
            throw std::runtime_error("Error\ndivision by zero");
        *result  = (first / second);   
        }
    if (*result > INT_MAX || *result < INT_MIN  )
            throw std::overflow_error("Error\ninteger overflow");
}

bool RPN::calculate(const std::string &numbers){
    long long result = 0;
    if(!checkValues(numbers))
        return false;
    for(auto it:numbers){
        if (it != ' '){
            switch (it){
                case 43:
                    transaction('+', &result);
                    rpnStack.push(result);
                    break;
                case 45: 
                    transaction('-', &result);
                    rpnStack.push(result);
                    break;
                case 42: 
                    transaction('*', &result);
                    rpnStack.push(result);
                    break;
                case 47: 
                    transaction('/', &result);
                    rpnStack.push(result);
                    break;
                default:
                    rpnStack.push(it - '0');
            }
        }
    }
    print_stack();
    return true;
}
