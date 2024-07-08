#include "ScalarConverter.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2) {
		std::cerr << "Invalid argument count" << std::endl;
		return 1;
	}

	std::string str(argv[1]);
	if (str.size() == 0) {
		std::cerr << "Invalid argument" << std::endl;
		return 1;
	}

	ScalarConverter::convert(str);
	return 0;
}
