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
		this->oddPair = other.oddPair;
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
	setBegin();

	for (size_t i = 1; argv[i]; i++)
	{
		tmpVec.push_back(static_cast<int>(strtod(argv[i], 0)));
	}


	if (tmpVec.size() % 2 == 1) {
		odd = true;
		unpaired = tmpVec.back();
		this->oddPair = std::make_pair(tmpVec.back(), tmpVec.back());
		tmpVec.pop_back();
	}

	for (size_t i = 0; i + 1 < tmpVec.size(); i+=2)
	{
		this->push_back(std::make_pair(tmpVec[i], tmpVec[i + 1]));
	}

	sortPairs();

	*this = mergeSort(*this);

	std::vector<int> sorted;
	sorted.reserve((this->size() * 2) + 1);
	sorted.push_back(this->at(0).first);
	sorted.push_back(this->at(0).second);
	this->erase(this->begin());
	addBiggerOfPair(sorted);
	std::cout << sorted << std::endl;

	*this = jacobsort();

	insert(sorted);

	setEnd();
	std::cout << "after:   " << sorted << std::endl;
	this->sortedResult = sorted;
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

	// std::cout << "jacob " << jacobSequence << std::endl;
	// std::cout << "*this " << *this << std::endl;
	for (size_t i = 0; this->size(); i++)
	{
		// std::cout << "Making group of size " << jacobSequence[i] << std::endl;
		for (size_t j = std::min(jacobSequence[i], this->size()); j > 0; j--)
		{
			// std::cout << this->at(j - 1).first << "j>" << j << std::endl;
			result.push_back(this->at(j - 1));
			this->erase(this->begin() + j - 1);
		}
	}
	return result;
}

void VectorSort::binaryInsert(std::vector<int>& final, int value, size_t start, size_t end, size_t middle) {
	// std::cout << "v b e m" << std::endl;
	while (start < end)
	{
		// std::cout << "indexes " << value << " " << start << " " << end << " " << middle << std::endl;
		// std::cout << "values " << value << " " << final.at(start) << " " << final.at(end) << " " << final.at(middle) << std::endl;
		if (final.front() > value) {
			final.insert(final.begin(), value);
			return;
		}
		if (final.at(middle) < value && (middle == final.size() - 1 || final.at(middle + 1) > value)) { 
			break;
		} else if (final.at(middle) > value) {
			end = middle;
			middle = end / 2;
		} else if (final.at(middle) < value) {
			start = middle;
			middle = ((end - start) / 2) + start;
		}
		// std::cout << std::endl;
	}
	final.insert(final.begin() + middle + 1, value);
}

std::vector<int> VectorSort::insert(std::vector<int>& final) {
	while (this->size())
	{
		// std::cout << "final " << final << std::endl;
		int value = this->at(0).first;
		size_t start = 0;
		size_t end = findValIndex(final, this->at(0).second);
		size_t middle = end / 2;
		binaryInsert(final, value, start, end, middle);
		this->erase(this->begin());
	}
	if (this->odd) {
		if (final.back() < this->oddPair.first) {
			final.push_back(this->oddPair.first);
		} else if (final.front() > this->oddPair.first) {
			final.insert(final.begin(), this->oddPair.first);
		} else {
			binaryInsert(final, this->oddPair.first, 0, final.size(), final.size() / 2);
		}
	}
	return final;
}

size_t VectorSort::findValIndex(std::vector<int>& final, int value) {
	if (final.size() > this->size()) {
		for (size_t i = final.size() - 1; i > 0; i--)
		{
			if (final.at(i) == value)
				return i;
		}
	} else {
		for (size_t i = 0; i < final.size(); i++)
		{
			if (final.at(i) == value)
				return i;
		}
	}
	return 0;
}

void VectorSort::isSorted(std::vector<int>& final) {
	for (size_t i = 0; i < final.size() - 1; i++)
	{
		if (final[i] > final[i + 1]) {
			std::cerr << "\x1B[91mList is not sorted\033[0m\n " << final[i] << " " << final[i + 1]  << std::endl;
			return;
		}
	}
	std::cout << "\x1B[92mList is sorted\033[0m\n" << std::endl;
}

std::vector<int>& VectorSort::getSorted() {
	return this->sortedResult;
}
