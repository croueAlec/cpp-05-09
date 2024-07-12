#pragma once

#include <cstddef>
#include <iostream>

template <typename T>
Array<T>::Array() : array(new T[0]), len(0) { }

template <typename T>
Array<T>::Array(unsigned int n) : array(new T[n]), len(n) {
	for (size_t i = 0; i < n; i++)
	{
		array[i] = 0;
	}
}

template <typename T>
Array<T>::Array(Array& other) : array(new T[other.size()]), len(other.size()) {
	for (size_t i = 0; i < other.size(); i++)
	{
		array[i] = other.array[i];
	}
}

template <typename T>
Array<T>::~Array() {
	delete [] array;
}

template <typename T>
const Array<T>& Array<T>::operator=(Array& other) {
	if (this != &other) {
		this->len = other.len;
		if (array)
			delete [] array;
		array = new T[this->len];
		for (size_t i = 0; i < this->len; i++)
		{
			this->array[i] = other.array[i];
		}
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](size_t n) const {
	if (n >= this->size()) {
		throw OutOfBoundsException();
	}

	return array[n];
}

template <typename T>
size_t Array<T>::size() const {
	return len;
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw() {
	return "Index is out of bounds";
}

template <typename T>
std::ostream& operator<<(std::ostream& ostream, const Array<T>& array) {
	for (size_t i = 0; i < array.size(); i++)
	{
		ostream << " ";
		ostream << array[i];
	}
	return ostream;
}
