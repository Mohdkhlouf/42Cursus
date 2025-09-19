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

template <typename T>
typename T::iterator easyfind(T &v, int v2){
    typename T::iterator it = std::find(v.begin(), v.end(), v2);
    if (it != v.end()){
        return (it);
	}
	throw value_not_found("Element not found");
}

template <typename T>
typename T::const_iterator easyfind(const T &v, int v2){
    typename T::const_iterator it = std::find(v.begin(), v.end(), v2);
    if (it != v.end()){
        return (it);
	}
	throw value_not_found("Element not found");
}
