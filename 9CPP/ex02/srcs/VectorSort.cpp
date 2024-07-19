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
VectorSort& VectorSort::operator=(const std::vector<std::pair<int, int> >& other) {
	this->clear();
	for (size_t i = 0; i < other.size(); i++)
	{
		this->push_back(other[i]);
	}
	return *this;
}

VectorSort::VectorSort(const char *argv[]) : unpaired(0), odd(false) {
	std::vector<int> tmpVec;
	for (size_t i = 1; argv[i]; i++)
	{
		tmpVec.push_back(static_cast<int>(strtod(argv[i], 0)));
	}

	setBegin();
	std::pair<int, int> oddPair;

	if (tmpVec.size() % 2 == 1) {
		odd = true;
		unpaired = tmpVec.back();
		oddPair = std::make_pair(tmpVec.back(), tmpVec.back());
		tmpVec.pop_back();
	}

	for (size_t i = 0; i + 1 < tmpVec.size(); i+=2)
	{
		this->push_back(std::make_pair(tmpVec[i], tmpVec[i + 1]));
	}

	sortPairs();

	//TODO: appliquer la suite du tri ne pas oublier la oddPair

	*this = mergeSort(*this);

	setEnd();
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
	struct timeval tv;
	gettimeofday(&tv, NULL);
	begin = tv.tv_usec;
}

void VectorSort::setEnd() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	end = tv.tv_usec;
}

std::time_t VectorSort::getTotTime() {
	return end - begin;
}

std::vector<std::pair<int, int> > VectorSort::mergeSort(std::vector<std::pair<int, int> > split) {
	if (split.size() > 1) {
		// std::cout << split << std::endl;
		size_t half = split.size() / 2;
		std::vector<std::pair<int, int> > low(split.begin(), split.begin() + half);
		std::vector<std::pair<int, int> > high(split.begin() + half, split.end());
		// std::cout << half << std::endl;
		// std::cout << "low " << low << std::endl;
		// std::cout << "high " << high << std::endl;
		// std::cout << "split " << split << std::endl;
		if (low.size() > 1)
			low = mergeSort(low);
		if (high.size() > 1)
			high = mergeSort(high);
		split = low + high;
		// std::cout << "split " << split << std::endl;
	}
	return split;
}

void VectorSort::sortPairs() {
	for (size_t i = 0; i < this->size(); i++)
	{
		if (this->at(i).first > this->at(i).second) {
			std::swap(this->at(i).first, this->at(i).second);
		}
	}
}
