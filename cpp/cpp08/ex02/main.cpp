#include "MutantStack.hpp"
#include <iostream>

int	main(void)
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);

	std::cout <<"Mutant stack top:"<<mstack.top() << std::endl;
	mstack.pop();
	
	std::cout <<"\nMutant stack size:"<< mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator itEnd = mstack.end();
	++it;
	--it;
	std::cout<<"\nMutant stack members:"<<std::endl;
	while (it != itEnd)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout<<"\nMutant stack members with for loop:"<<std::endl;
	for (auto iterator = mstack.begin(); iterator != mstack.end(); iterator++)
	{
		std::cout<<*iterator<<std::endl;
	}
	
	return (0);
}