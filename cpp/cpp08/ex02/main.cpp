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


	auto it = mstack.begin();
	auto itEnd = mstack.end();
	std::cout<<"\nMutant stack members:"<<std::endl;
	while (it != itEnd)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	auto mstack_begin = mstack.begin();
	std::cout<<"mstack_begin value: "<<*mstack_begin<<std::endl;
	auto mstack_end= mstack.end();
	std::cout<<"mstack_end value: "<<*(mstack_end-2)<<std::endl;
	auto mstack_rbegin = mstack.rbegin();
	std::cout<<"mstack_rbegin value: "<<*mstack_rbegin<<std::endl;
	auto mstack_rend= mstack.rend();
	std::cout<<"mstack_rend value: "<<*(mstack_rend - 2)<<std::endl;
	
	return (0);
}