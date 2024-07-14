#pragma once

#include <deque>
#include <stack>
#include <iostream>

template <typename T, typename container = std::deque<T> >
class MutantStack : public std::stack<T, container> {
  public:
	MutantStack() {};
	MutantStack(container cont) : std::stack<T, container>(cont) {};
	~MutantStack() {};
	MutantStack(const MutantStack& other) {
		*this = other;
	}

	MutantStack& operator=(const MutantStack& other) {
		if (this != &other) {
			std::stack<T, container>::operator=(other);
		}
		return *this;
	}

	typedef typename container::iterator iterator;
	iterator begin(void) {
		return this->c.begin();
	}

	iterator end(void) {
		return this->c.end();
	}
};

template <typename T>
std::ostream& operator<<(std::ostream& os, MutantStack<T>& mstack) {
	for (std::size_t i = 0; i < mstack.size(); i++)
	{
		os << *(mstack.begin() + i) << " ";
	}
	return os;
}
