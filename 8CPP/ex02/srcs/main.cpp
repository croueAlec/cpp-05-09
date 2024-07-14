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

int main(void) {
	std::cout << "Subject example:" << std::endl;
	subjectExample();
	std::cout << "\nList example:" << std::endl;
	listExample();
}
