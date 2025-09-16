#include "Array.hpp"
#include <stdexcept>

template <typename T>
Array<T>::Array():arrPtr(nullptr),elementsNumber(0){}

template<typename T>
Array<T>::Array(unsigned int n){
	elementsNumber = n;
	arrPtr = new T[n];
}

template<typename T>
Array<T>::Array(const Array &obj):arrPtr(obj.arrPtr),elementsNumber(0){};

template<typename T>
Array<T>& Array<T>::operator=(const Array &obj){
	if(this != &obj){
		delete []arrPtr;
		arrPtr = obj.arrPtr;
		elementsNumber = obj.elementsNumber;
		for(unsigned int i = 0; i < elementsNumber; i++){
			arrPtr[i] = obj.arrPtr[i];
		}
	}
	return (*this);
}

template<typename T>
unsigned int Array<T>::size() const{
	return (elementsNumber);
}

template<typename T>
T& Array<T>::operator[](unsigned int index){
	if (index >= elementsNumber || index < 0)
		throw std::out_of_range("index is larger than array max");
	return arrPtr[index];
}


template<typename T>
const T& Array<T>::operator[](unsigned int index) const{
	if (index >= elementsNumber || index < 0)
		throw std::out_of_range("index is larger than array max");
	return arrPtr[index];
}

template<typename T>
Array<T>::~Array(){
	delete [] arrPtr;
}

