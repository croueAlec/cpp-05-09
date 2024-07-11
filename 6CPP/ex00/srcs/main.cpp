#include "ScalarConverter.hpp"

void	example(const std::string& tmp) {
	std::cout << tmp << std::endl;
	ScalarConverter::convert(tmp);
	std::cout << std::endl;
}

void	subjectTests() {
	example("0");

	example("nan");

	example("42.0f");

	std::cout << "==--------==" << std::endl << std::endl;
}

void	ownTests() {
	example("salut");

	example("12788956");

	example("12.");

	example("47.5");

	example("1.234567890");

	std::cout << "==--------==" << std::endl << std::endl;
}

int main(int argc, char const *argv[])
{
	subjectTests();

	ownTests();

	if (argc != 2) {
		std::cerr << "Invalid argument count" << std::endl;
		return 1;
	}

	std::string str(argv[1]);
	if (str.size() == 0) {
		std::cerr << "Invalid argument" << std::endl;
		return 1;
	}

	std::cout << str << std::endl;
	ScalarConverter::convert(str);
	return 0;
}
