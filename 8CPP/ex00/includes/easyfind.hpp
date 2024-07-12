#pragma once

#include <iostream>
#include <algorithm>

class NotFoundException : public std::exception {
  public:
	virtual const char* what() const throw();
};
const char* NotFoundException::what() const throw() {
	return "Element not found";
}

template<typename T>
void easyfind(T& container, int value) {
	if (std::find(container.begin(), container.end(), value) == container.end()) {
		throw NotFoundException();
	} else {
		std::cout << "Found " << *std::find(container.begin(), container.end(), value) << " in container" << std::endl;
	}
}
