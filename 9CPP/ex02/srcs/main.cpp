#include <iostream>
#include <vector>
#include <algorithm>

#include "VectorSort.hpp"

class InvalidInputException : public std::exception {
  public:
	virtual const char* what() const throw();
};
const char* InvalidInputException::what() const throw() {
	return "Error";
}
class DuplicateException : public std::exception {
  public:
	virtual const char* what() const throw();
};
const char* DuplicateException::what() const throw() {
	return "Error : duplicates";
}

void isListValid(char const *argv[]) {
	std::vector<int> tmp;
	double value = 0;

	for (size_t i = 1; argv[i]; i++)
	{
		std::string str(argv[i]);
		if (str.find_first_not_of("0123456789") != str.npos)
			throw InvalidInputException();
		value = strtod(argv[i], 0);
		if (value > 2147483647 || value < -2147483648)
			throw InvalidInputException();
		tmp.push_back(static_cast<int>(value));
	}
	std::sort(tmp.begin(), tmp.end());
	for (std::vector<int>::iterator it = tmp.begin(); it + 1 != tmp.end(); it++)
	{
		// std::cout << *it << " " << *(it + 1) << std::endl;
		if (*it == *(it + 1))
			throw DuplicateException();
	}
}

void displayDefault(const char *argv[]) {
	std::cout << "before:  " << std::flush;
	for (size_t i = 1; argv[i]; i++)
	{
		std::cout << argv[i] << " " << std::flush;
	}
	std::cout << std::endl;
}

void displayTime(int size, VectorSort& vec) {
	std::cout << "Time to process a range of " << size << " elements with std::vector : " << vec.getTotTime() << " TimeUnit(s)" << std::endl;
}

int main(int argc, char const *argv[]) {
	if (argc == 1) {
		std::cerr << "Error : Invalid argument count" << std::endl;
		return 1;
	}

	try
	{
		isListValid(argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}

	displayDefault(argv);

	VectorSort vec(argv);

	std::cout << vec << std::endl;
	displayTime(argc - 1, vec);

	return 0;
}
