#include "MutantStack.hpp"
#include <iostream>
#include <list>

void subjectExample() {
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << " <Top of the stack (last in)" << std::endl;
	mstack.pop();
	std::cout << mstack.size() << " <Stack size" << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
}

void listExample() {
	std::list<int> list;

	list.push_back(5);
	list.push_back(17);
	std::cout << list.back() << " <Back of the list (last in)" << std::endl;
	list.pop_back();
	std::cout << list.size() << " <List size" << std::endl;
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	//[...]
	list.push_back(0);
	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator ite = list.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
}

void otherTests() {
	MutantStack<size_t> mstack;

	std::cout << "For each element divisible by 3 in the stack I remove the last element" << std::endl;
	for (size_t i = 0; i < 15; i++)
	{
		mstack.push(mstack.size() * 7);
	}
	std::cout << mstack << std::endl;

	for (MutantStack<size_t>::iterator it = mstack.begin(); it != mstack.end(); it++)
	{
		if (*it % 3 == 0 && *it != 0) {
			std::cout << *it << " is divisible by 3" << std::endl;
			std::cout << "Removing " << *(mstack.end() - 1) << " from mstack" << std::endl;
			mstack.pop();
		}
	}
	std::cout << mstack << std::endl;
}

int main(void) {
	std::cout << "Subject example:" << std::endl;
	subjectExample();
	std::cout << "\nList example:" << std::endl;
	listExample();
	std::cout << "\nOther examples:" << std::endl;
	otherTests();
}
