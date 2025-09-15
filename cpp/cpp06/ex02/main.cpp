#include <ctime>
#include <stdlib.h>
#include "Base.hpp"

int main()
{
	try
	{
		std::srand(time(NULL));

		Base *baseValue;
		baseValue = generate();
		identify(baseValue);

		Base &BaseRef = *baseValue;
		identify(BaseRef);

		std::cout<<"\ntest with object not done by the generate function"<<std::endl;
		Base *nullValue = nullptr;
		identify(nullValue);

		delete baseValue;
	}catch(const std::exception &e){
		std::cout<<"Catched error: "<<e.what()<<std::endl;
	}

	return (0);
}