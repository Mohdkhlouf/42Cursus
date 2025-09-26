#pragma once

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>{
	public:
		class iterator{
			private:
				typename std::deque<T>::reverse_iterator iter_;
			public:


		};




		iterator begin(){
			return (this->c.begin());
		}

};