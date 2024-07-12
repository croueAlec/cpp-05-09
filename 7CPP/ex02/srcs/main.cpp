#include <cstdlib>
#include <exception>
#include <iostream>
#include "Array.hpp"

const size_t SIZE = 8;

void invalidAccess() {
	Array<char> invalid(SIZE);

	try
	{
		invalid[SIZE * 2] = 100;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void arrayCopy() {
	Array<unsigned int> arrayOne(SIZE);
	Array<unsigned int> arrayTwo(SIZE / 2);

	for (size_t i = 0; i < SIZE; i++)
	{
		arrayOne[i] = SIZE * i * 2;
	}

	arrayTwo = arrayOne;
	Array<unsigned int> arrayThree(arrayOne);

	std::cout << "arrayOne:" << arrayOne << std::endl;
	std::cout << "arrayTwo:" << arrayTwo << std::endl;
	std::cout << "arrayThree:" << arrayThree << std::endl;
}

int main(void) {
	Array<int> arr(SIZE);

	std::cout << "Default array:" << arr << std::endl;

	for (size_t i = 0; i < SIZE; i++)
	{
		arr[i] = SIZE * i;
	}
	std::cout << "Set array:" << arr << std::endl;

	invalidAccess();

	arrayCopy();

	return 0;
}
