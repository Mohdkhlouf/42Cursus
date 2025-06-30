#include <stdio.h>
#include <iostream>
#include "Sample.class.cpp"

int main(void)
{
	Sample hello;
	hello.x = 44;
	hello.print();
	std::cout << hello.x <<std::endl;
	
	return (0);
}
