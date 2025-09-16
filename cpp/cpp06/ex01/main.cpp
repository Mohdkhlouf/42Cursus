#include "Serializer.hpp"

int main()
{
	try
	{
		Data d;
		d.name = "mohammad";
		d.x = 40;

		Data *dPtr = &d;
		std::cout << "dPtr\n"
				  << "Name:" << dPtr->name << " Age:" << dPtr->x << std::endl;
		std::cout << "Address of the dPtr: " << dPtr << "\n";

		uintptr_t ptr = Serializer::serialize(dPtr);
		std::cout << "address of the dPtr after serialize:" << ptr << std::endl;

		Data *dPtr2 = Serializer::deserialize(ptr);
		std::cout << "\ntest deserializer by creating new dPtr2 point to the result of the deserialize:\n"
				  << "Name:" << dPtr2->name << " Age:" << dPtr2->x << std::endl;
		std::cout << "Address of the dPtr2: " << dPtr2 << "\n";

		std::cout << "\ntest if they are same" << std::endl;
		if (dPtr == dPtr2)
			std::cout << "SUCCESS!\n";
		else
			std::cout << "FAILED!\n";
	}catch (const std::exception &e){
		std::cout<<"Error:"<<e.what()<<std::endl;
	}

	return (0);
}