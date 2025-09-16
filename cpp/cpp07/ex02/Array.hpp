#pragma once
#include <ostream>
#include <iostream>

template<typename T>
class Array{
	private:
		T *arrPtr;
		unsigned int elementsNumber;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array &obj);
		~Array();
		Array &operator=(const Array &obj);
		T &operator[](unsigned int index);
		const T& operator[](unsigned int index) const;
		unsigned int size() const;


};
