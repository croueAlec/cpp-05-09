#include <cstdlib>
#include <unistd.h>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void) {
	srand(rand());

	switch (rand() % 3)
	{
	case 0:
		std::cout << "A has been generated" << std::endl;
		return new A();

	case 1:
		std::cout << "B has been generated" << std::endl;
		return new B();

	case 2:
		std::cout << "C has been generated" << std::endl;
		return new C();
	}
	return NULL;
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "Pointer p is of type A" << std::endl;
		return;
	}

	if (dynamic_cast<B*>(p)) {
		std::cout << "Pointer p is of type B" << std::endl;
		return;
	}

	if (dynamic_cast<C*>(p)) {
		std::cout << "Pointer p is of type C" << std::endl;
		return;
	}
}

void identify(Base& p) {
	try
	{
		(void)dynamic_cast<A &>(p);
	}
	catch(const std::exception& e)
	{
		try
		{
			(void)dynamic_cast<B &>(p);
		}
		catch(const std::exception& e)
		{
			std::cout << "Reference p is of type C" << std::endl;
			return;
		}
		std::cout << "Reference p is of type B" << std::endl;
		return;
	}
	std::cout << "Reference p is of type A" << std::endl;
	return;
}

void basicTest() {
	Base* a = new A();
	Base* b = new B();
	Base* c = new C();

	identify(a);
	identify(b);
	identify(c);

	std::cout << std::endl;

	identify(*a);
	identify(*b);
	identify(*c);

	delete a;
	delete b;
	delete c;
}

void randomTest() {
	Base* rand = generate();

	identify(rand);
	identify(*rand);

	delete rand;
}

int main(void) {
	srand(time(0));
	basicTest();

	for (size_t i = 0; i < 4; i++)
	{
		std::cout << std::endl;
		randomTest();
	}

	return 0;
}
