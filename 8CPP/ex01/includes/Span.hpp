#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

class Span {
  private:
	std::vector<int> vec;
	size_t size;
  public:
	Span();
	Span(size_t size);
	Span(const Span& other);
	~Span();
	Span& operator=(const Span& other);

	void addNumber(int n);
	class FullArrayException : public std::exception {
	  public:
		virtual const char* what() const throw();
	};

	class NoSpanFoundException : public std::exception {
	  public:
		virtual const char* what() const throw();
	};

	int shortestSpan();
	int longestSpan();

	std::vector<int>::iterator begin();
	std::vector<int>::iterator end();

	Span(std::vector<int>::iterator begin, std::vector<int>::iterator end, size_t size);
	// #include <deque>
	// template <typename T, template container = deque<T> >
};

std::ostream& operator<<(std::ostream& os, Span& span);
