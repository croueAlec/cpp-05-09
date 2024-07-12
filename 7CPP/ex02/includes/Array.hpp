#pragma once

#include <cstddef>
#include <exception>
#include <ostream>
#include <iostream>

template <typename T>
class Array {
  private:
	T *array;
	size_t len;
  public:
	Array();
	Array(unsigned int n);
	Array(Array& other);
	~Array();

	const Array& operator=(Array& other);
	T& operator[](size_t n) const;
	size_t size() const;

	class OutOfBoundsException : public std::exception {
	  public:
		virtual const char* what() const throw();
	};
};

#include "Array.tpp"

template <typename T>
std::ostream& operator<<(std::ostream& ostream, const Array<T>& array);
