#pragma once
#include <iostream>

template<typename T>
void function(const T& v){
	std::cout<<"Value is:"<<v<<"\n";
}


template<typename T>
void Iter(T *arrAddress, int arrayLength, void(*arrFunc)(const T&)){
	if(arrAddress == nullptr || arrFunc == nullptr)
		return;
	for(int i = 0;i < arrayLength; i++){
		arrFunc(arrAddress[i]);
	}
}


