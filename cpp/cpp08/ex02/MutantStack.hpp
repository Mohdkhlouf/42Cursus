#pragma once
#include <deque>
#include <stack>

template <typename T> class MutantStack : public std::stack<T>
{
  public:
	class iterator
	{
		private:
		typename std::deque<T>::reverse_iterator iter_;

		public:
		iterator(typename std::deque<T>::reverse_iterator it) : iter_(it){};
		T &operator*() const
		{
			return (*iter_);
		};

		T *operator->() const
		{
			return (&(*iter_));
		};

		iterator &operator++()
		{
			++iter_;
			return (*this);
		};

		iterator operator++(int)
		{
			iterator temp = *this;
			++iter_;
			return (temp);
		};

		iterator &operator--()
		{
			--iter_;
			return (*this);
		};

		iterator operator--(int)
		{
			iterator temp = *this;
			--iter_;
			return (temp);
		};

		bool operator==(const iterator &obj)const{
			return (iter_ == obj.iter_);
		};

		bool operator!=(const iterator &obj) const{
			return (iter_ != obj.iter_);
		};
	};

	iterator begin()
	{
		return (iterator(this->c.rbegin()));
	};

	iterator end()
	{
		return (iterator(this->c.rend()));
	};

	iterator rbegin()
	{
		return (iterator(this->c.begin()));
	};

	iterator rend()
	{
		return (iterator(this->c.end()));
	};
};