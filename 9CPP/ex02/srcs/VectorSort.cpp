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

	std::vector<int> sorted;
	sorted.reserve((this->size() * 2) + 1);
	sorted.push_back(this->at(0).first);
	sorted.push_back(this->at(0).second);
	this->erase(this->begin());
	addBiggerOfPair(sorted);

	*this = jacobsort();
	

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
	begin_time = tv.tv_usec;
}

void VectorSort::setEnd() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	end_time = tv.tv_usec;
}

std::time_t VectorSort::getTotTime() {
	return end_time - begin_time;
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

void VectorSort::addBiggerOfPair(std::vector<int>& sorted) {
	for (size_t i = 0; i < this->size(); i++)
	{
		sorted.push_back(this->at(i).second);
	}
}

std::vector<size_t> VectorSort::jacobstyle(size_t j) {
	std::vector<size_t> jacob;
	jacob.push_back(2);
	jacob.push_back(2);
	for (size_t i = 1; i < j; i++)
	{
		size_t val = jacob[i] + (jacob[i - 1] * 2);
		jacob.push_back(val);
	}
	return jacob;
}

std::vector<std::pair<int, int> > VectorSort::jacobsort() {
	std::vector<size_t> jacobSequence = jacobstyle(this->size());
	std::vector<std::pair<int, int> > result;

	std::cout << "jacob " << jacobSequence << std::endl;
	std::cout << this << std::endl;
	for (size_t i = 0; this->size(); i++)
	{
		std::cout << "Making group of size " << jacobSequence[i] << std::endl;
		for (size_t j = std::min(jacobSequence[i], this->size()); j > 0; j--)
		{
			std::cout << this->at(j - 1).first << " " << j << std::endl;
			result.push_back(this->at(j - 1));
			this->erase(this->begin() + j - 1);
		}
	}
	return result;
}

std::vector<int> VectorSort::insert(std::vector<int>& final) {

}
