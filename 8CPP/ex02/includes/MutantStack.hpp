#pragma once

#include <deque>
#include <stack>

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
