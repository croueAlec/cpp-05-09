#include "easyfind.hpp"

#include <vector>

int main(void)
{
	std::vector<int> vec;

	for (size_t i = 0; i < 10; i++)
	{
		vec.push_back(i * 3);
	}

	for (size_t i = 0; i < 9; i++)
	{
		try
		{
			easyfind(vec, i);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	return 0;
}
