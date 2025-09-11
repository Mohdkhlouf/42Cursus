#include <ctime>
#include <stdlib.h> 
#include "Base.hpp"

int main(){
	std::srand(time(NULL));
	
	Base * baseValue;
	baseValue = generate();
	identify(baseValue);

	Base &BaseRef = * baseValue;
	identify(BaseRef);

	return (0);
}