#include "Span.hpp"
#include <cstdlib>

void subjectTest()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void ownBasicTest() {
	Span vec(10);

	for (int i = 0; i < 10; i++)
	{
		vec.addNumber(i);
	}
	std::cout << vec << std::endl;
}

void exceptions() {

{	Span full(3);
	for (int i = 0; i < 5; i++)
	{
		try
		{
			full.addNumber(i);
			std::cout << "adding " << i << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}}

{	std::cout << std::endl;
	Span empty(0);
	try
	{
		empty.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}}

{	std::cout << std::endl;
	Span one(1);
	try
	{
		one.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}}
}

void big() {
	srand(time(0));
	Span bigger(10500);

	for (size_t i = 0; i < 10500; i++)
	{
		bigger.addNumber(rand());
	}
	std::cout << bigger << std::endl;

	Span small(bigger.begin(), bigger.end() + 10, 10);
	std::cout << small << std::endl;
}

void lastTest() {
	Span test(4);

	test.addNumber(0);
	test.addNumber(1);
	test.addNumber(5);
	test.addNumber(-17);
	std::cout << test << std::endl;
}

int main(void)
{
	subjectTest();

	std::cout << std::endl;
	ownBasicTest();

	std::cout << std::endl;
	exceptions();

	std::cout << std::endl;
	big();

	std::cout << std::endl;
	lastTest();
	return 0;
}
