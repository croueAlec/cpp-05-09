#include "whatever.hpp"
#include <iostream>

template <typename T>
void swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T min(T& a, T& b) {
	if (a == b)
		return b;

	return (a < b) ? a : b;
}

template <typename T>
T max(T& a, T& b) {
	if (a == b)
		return b;

	return (a > b) ? a : b;
}

void swapExample() {
	int a = 15;
	int b = 18;

	std::cout << a << " " << b << std::endl;
	std::cout << "  x" << std::endl;
	::swap(a, b);
	std::cout << a << " " << b << std::endl;
	std::cout << std::endl;
}

void minExample() {
	int a = 117;
	int b = 23;

	std::cout << ::min(a, b) << " is smaller than " << ::max(a, b) << std::endl;;
}

void maxExample() {
	double a = 117;
	double b = 23;

	std::cout << ::max(a, b) << " is bigger than " << ::min(a, b) << std::endl;
}

void equalsExample() {
	size_t a = 8;
	size_t b = 9;

	std::cout << ::max(a, a) << " equals " << ::max(a, a) << std::endl;
	std::cout << ::max(b, b) << " equals " << ::max(b, b) << std::endl;
}

// int main(void) {
// 	swapExample();

// 	minExample();

// 	std::cout << std::endl;
// 	maxExample();

// 	std::cout << std::endl;
// 	equalsExample();

// 	return 0;
// }

int main( void ) {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}
