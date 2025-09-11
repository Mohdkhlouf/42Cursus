
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(){
	std::cout<<"Base Destroyer destructor started."<<std::endl;
}

Base * generate(void){
	int randv = rand() %3;

	switch (randv){
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
	}
	return (nullptr);
}


void identify(Base* p){
	if (A *a = dynamic_cast<A*>(p)){
		std::cout<<"it is from A Type"<<std::endl;
	}
	else if (B *b = dynamic_cast<B*>(p)){
		std::cout<<"it is from B Type"<<std::endl;
	}
	else if (C *c = dynamic_cast<C*>(p)){
		std::cout<<"it is from C Type"<<std::endl;
	}
}

void identify(Base& p){

	try{
		A & aRef = dynamic_cast<A&>(p);
		(void) aRef;
		std::cout<<"the refrence is from A Type"<<std::endl;
		return;
	}catch (...){}


	try{
		B & bRef = dynamic_cast<B&>(p);
		(void) bRef;
		std::cout<<"the refrence is from B Type"<<std::endl;
		return;
	}catch (...){}


	try{
		C & cRef = dynamic_cast<C&>(p);
		(void) cRef;
		std::cout<<"the refrence is from C Type"<<std::endl;
		return;
	}catch (...){}
	
	std::cout<<"the refrence is from Uknown Type"<<std::endl;
}