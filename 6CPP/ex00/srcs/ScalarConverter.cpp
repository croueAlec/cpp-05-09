#include "ScalarConverter.hpp"

#include <cstdlib>

ScalarConverter::ScalarConverter() {
	std::cout << "Default constructor for the ScalarConverter class called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	std::cout << "Copy constructor for the ScalarConverter class called" << std::endl;
	*this = other;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "Default destructor for the ScalarConverter class called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	std::cout << "Copy assignment operator for the ScalarConverter class called" << std::endl;
	(void)other;
	return *this;
}

void	convertToChar(std::string& literal) {
	if (literal.size() == 1 && isprint(literal[0])) {
		std::cout << literal[0] << std::endl;
		return;
	}

	char *end;
	char ch = static_cast<char>(strtol(literal.c_str(), &end, 10));
	if (end != '\0')
		return;
	std::cout << ch << std::endl;
}

// bool	checkFloat(std::string& literal) {
// 	int status = 0;

// 	for (size_t i = 0; i < literal.size(); i++)
// 	{
// 		std::cout << &literal[i] << std::endl;
// 		if (status == 0) {
// 			if (isdigit(literal[i]))
// 				continue;
// 			else
// 				status = 1;
// 		}
// 		if (status == 1) {
// 			// std::cout << literal[i] << "ici" << std::endl;
// 			if (literal[i] == '.')
// 				status = 2;
// 			else
// 				return (0);
// 		}
// 		else if (status == 2) {
// 			if (isdigit(literal[i]))
// 				continue;
// 			else if (literal[i] == )
// 				status = 3;
// 		}
// 		if (status == 4) {
// 			if (literal[i] == 'f')
// 				status = 5;
// 			else
// 				return (0);
// 		}
// 	}
// 	return (status == 5);
// }

void	convertToFloat(std::string& literal) {
	// if (checkFloat(literal)) {
	// 	std::cout << literal << std::endl;
	// }
	char *end;
	float f = strtof(literal.c_str(), &end);
	std::cout << f << std::endl;
}

void	ScalarConverter::convert(std::string& literal) {
	if (literal.size() == 0) {
		std::cerr << "Invalid literal" << std::endl;
		return;
	}
	convertToChar(literal);
	convertToFloat(literal);
}
