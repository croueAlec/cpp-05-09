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

void	convertToChar(const std::string& literal) {
	std::cout << "char: " << std::flush;

	char *end = NULL;
	double value = strtod(literal.c_str(), &end);
	std::string tmp(end);

	if (literal == "nan" || (!tmp.empty() && tmp != "f") || (value < -128 || value > 127)) {
		std::cout << "impossible" << std::endl;
		return;
	}

	char char_value = static_cast<char>(value);

	if (!isprint(char_value)) {
		std::cout << "Non displayable" << std::endl;
		return;
	}

	std::cout << "\'" << char_value << "\'" << std::endl;
	return;
}

void	convertToInt(const std::string& literal) {
	std::cout << "int: " << std::flush;

	char *end = NULL;
	double value = strtod(literal.c_str(), &end);
	std::string tmp(end);

	if ((literal == "nan" || (!tmp.empty() && tmp != "f")) || (value < MIN_INT || value > MAX_INT)) {
		std::cout << "impossible" << std::endl;
		return;
	}

	int int_value = static_cast<int>(value);

	std::cout << int_value << std::endl;
	return;
}

void	convertToFloat(const std::string& literal) {
	std::cout << "float: " << std::flush;

	char *end = NULL;
	double value = strtod(literal.c_str(), &end);
	std::string tmp(end);

	if (literal == "nan") {
		std::cout << "nanf" << std::endl;
		return;
	}

	if ((!tmp.empty() && tmp != "f")) {
		std::cout << "impossible" << std::endl;
		return;
	}

	std::cout << value << std::flush;
	if (value == floor(value))
		std::cout << ".0" << std::flush;
	std::cout << "f" << std::endl;
	return;
}

void	convertToDouble(const std::string& literal) {
	std::cout << "double: " << std::flush;

	char *end = NULL;
	double value = strtod(literal.c_str(), &end);
	std::string tmp(end);

	if (literal == "nan") {
		std::cout << "nan" << std::endl;
		return;
	}

	if ((!tmp.empty() && tmp != "f")) {
		std::cout << "impossible" << std::endl;
		return;
	}

	std::cout << value << std::flush;
	if (value == floor(value))
		std::cout << ".0" << std::flush;
	std::cout << std::endl;
	return;
}

bool	handleInf(const std::string& literal) {
	if (literal == "-inf" || literal == "+inf" || literal == "+inff" || literal == "-inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (literal[0] == '-') {
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
		} else {
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
		}
		return 1;
	}

	return 0;
}

void	ScalarConverter::convert(const std::string& literal) {
	if (literal.size() == 0) {
		std::cerr << "Invalid literal" << std::endl;
		return;
	}

	if (handleInf(literal)) {
		return;
	}

	convertToChar(literal);
	convertToInt(literal);
	convertToFloat(literal);
	convertToDouble(literal);
}
