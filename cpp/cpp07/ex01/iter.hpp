#pragma once
#include <iostream>

// Change to print
template<typename T>
void function(const T& v){
	std::cout<<"Value is:"<<v<<"\n";
}


template<typename T>
void Iter(T *arrAddress, int arrayLength, void(*arrFunc)(T &)){
	if(arrAddress == nullptr || arrFunc == nullptr)
		return;
	for(int i = 0;i < arrayLength; i++){
		arrFunc(arrAddress[i]);
	}
}

template<typename T>
void Iter(T *arrAddress, int arrayLength, void(*arrFunc)(const T&)){
	if(arrAddress == nullptr || arrFunc == nullptr)
		return;
	for(int i = 0;i < arrayLength; i++){
		arrFunc(arrAddress[i]);
	}
}

template<typename T>
void	increment(T value)
{
	value++;
}


class Awesome{
	public:
		Awesome(void):_n(42){return;}
		int get(void) const{ return this->_n;}
	private:
		int _n;

};

std::ostream &operator<<(std::ostream &o, Awesome const &rhs){
	o<<rhs.get();
	return o;
}

template<typename T>
void print( T const &x){
	std::cout <<x<<std::endl;
	return;
};

