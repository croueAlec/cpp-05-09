#include "Data.hpp"
#include "Serializer.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2) {
		std::cerr << "Invalid arg number" << std::endl;
		return 1;
	}

	Data* data = new Data();

	std::string tmp(argv[1]);
	data->str = tmp;
	data->value = tmp.size() * 2;

	std::cout << "Struct before: " << data->str << " " << data->value << std::endl;

	uintptr_t ptr = Serializer::serialize(data);
	Data* newPtr = Serializer::deserialize(ptr);

	std::cout << "Struct after: " << newPtr->str << " " << newPtr->value << std::endl;

	std::cout << data << std::endl;
	std::cout << newPtr << std::endl;

	return 0;
}

