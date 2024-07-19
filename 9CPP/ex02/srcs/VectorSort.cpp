#include "VectorSort.hpp"

VectorSort::VectorSort() : unpaired(0), odd(false) {
	// std::cout << "Default constructor for the VectorSort class called" << std::endl;
	this->push_back(std::make_pair(0, 0));
}

VectorSort::VectorSort(const VectorSort& other) : unpaired(0), odd(false) {
	// std::cout << "Copy constructor for the VectorSort class called" << std::endl;
	*this = other;
}

VectorSort::~VectorSort() {
	// std::cout << "Default destructor for the VectorSort class called" << std::endl;
}

VectorSort& VectorSort::operator=(const VectorSort& other) {
	// std::cout << "Copy assignment operator for the VectorSort class called" << std::endl;
	if (this != &other) {
		this->odd = other.odd;
		this->unpaired = other.unpaired;
		for (size_t i = 0; i < other.size(); i++)
		{
			this->push_back(other[i]);
		}
	}
	return *this;
}

VectorSort::VectorSort(const char *argv[]) : unpaired(0), odd(false) {
	std::vector<int> tmpVec;
	for (size_t i = 1; argv[i]; i++)
	{
		tmpVec.push_back(static_cast<int>(strtod(argv[i], 0)));
	}

	

	if (tmpVec.size() % 2 == 1) {
		odd = true;
		unpaired = tmpVec.back();
		this->push_back(std::make_pair(tmpVec.back(), tmpVec.back()));
		tmpVec.pop_back();
	}

	for (size_t i = 0; i + 1 < tmpVec.size(); i+=2)
	{
		this->push_back(std::make_pair(tmpVec[i], tmpVec[i + 1]));
	}
}

bool VectorSort::isUnpair(int value) {
	if (!odd)
		return false;

	return value == unpaired;
}

bool VectorSort::isUnpair(std::vector<std::pair<int, int> >::iterator& value) {
	if (!odd)
		return false;

	return (*value).first == unpaired;
}

bool VectorSort::isUnpair(std::pair<int, int>& value) {
	if (!odd)
		return false;

	return value.first == unpaired;
}

void VectorSort::setBegin() {
	begin = time(0);
}

void VectorSort::setEnd() {
	end = time(0);
}

std::time_t VectorSort::getTotTime() {
	return end - begin;
}
