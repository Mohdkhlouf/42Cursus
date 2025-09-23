#pragma once
#include <stdexcept>
#include <exception>
#include <iterator>
#include <iostream>
#include <algorithm>

class value_not_found : public std::exception{
    private:
        std::string message;

    public:
        value_not_found(const std::string &msg):message(msg){};
        const char * what() const noexcept override{
            return (message.c_str());
        }
};

// you have to have 2 functions because of the const or u can use auto
template <typename T>
auto easyfind(T &v, int v2){
   auto it = std::find(v.begin(), v.end(), v2);
    if (it != v.end()){
        return (it);
	}
	throw value_not_found("Element not found");
}