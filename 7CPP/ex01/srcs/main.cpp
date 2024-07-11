#include "iter.hpp"

void printFiveOf(int a) {
	for (size_t i = 0; i < 5; i++)
	{
		std::cout << a << " " << std::flush;
	}
	std::cout << std::endl;
}

void onlyLow(char a) {
	if (islower(a)) {
		std::cout << a << std::endl;
	}
}

template <typename T>
void iter(T* array, size_t size, void (*f)(T)) {
	for (size_t i = 0; i < size; i++)
	{
		f(array[i]);
	}
}

void print(int i)
{
	std::cout << i << std::endl;
}

int main(void)
{

	int nbr[5] = {25, 50, 100, 125, 150};
	char ch[5] = {'d', 'f', 'G', 'H', 'z'};

	iter(nbr, 5, *print);

	std::cout << std::endl;
	iter(nbr, 5, *printFiveOf);

	std::cout << std::endl;
	iter(ch, 5, *onlyLow);

	return 0;
}

