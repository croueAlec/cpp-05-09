#include "Span.hpp"

Span::Span() {
	std::cout << "Default constructor for the Span class called" << std::endl;
}

Span::Span(const Span& other) {
	std::cout << "Copy constructor for the Span class called" << std::endl;
	*this = other;
}

Span::~Span() {
	std::cout << "Default destructor for the Span class called" << std::endl;
}

Span& Span::operator=(const Span& other) {
	std::cout << "Copy assignment operator for the Span class called" << std::endl;
	if (this != &other) {
		this->size = other.size;
		this->vec = other.vec;
	}
	return *this;
}

Span::Span(size_t size) : size(size) { std::cout << "Parameted constructor" << std::endl; }

void Span::addNumber(int n) {
	if (vec.size() == size)
		throw FullArrayException();

	vec.push_back(n);
}

const char* Span::FullArrayException::what() const throw() {
	return "Array is already full";
}


const char* Span::NoSpanFoundException::what() const throw() {
	return "No span found";
}

int Span::shortestSpan() {
	if (size <= 1)
		throw NoSpanFoundException();

	int shortest = this->longestSpan();

	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		for (std::vector<int>::iterator jit = it + 1; jit != vec.end(); jit++) {
			int tmp = abs(*it - *jit);
			if (tmp < shortest)
				shortest = tmp;
		}
	}
	return shortest;
}

int Span::longestSpan() {
	if (size <= 1)
		throw NoSpanFoundException();

	std::vector<int>::iterator small = std::min_element(vec.begin(), vec.end());
	std::vector<int>::iterator big = std::max_element(vec.begin(), vec.end());

	return abs(*big - *small);
}

std::vector<int>::iterator Span::begin() {
	return vec.begin();
}
std::vector<int>::iterator Span::end() {
	return vec.end();
}

Span::Span(std::vector<int>::iterator begin, std::vector<int>::iterator end, size_t size) : size(size) {
	std::vector<int> tmp(begin, end);

	vec = tmp;
	vec.resize(size);
}

std::ostream& operator<<(std::ostream& os, Span& span) {
	os << "Shortest span is " << span.shortestSpan() << std::endl;
	os << "Longest span is " << span.longestSpan();
	return os;
}
