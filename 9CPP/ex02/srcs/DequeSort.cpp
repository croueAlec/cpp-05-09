#include "DequeSort.hpp"

DequeSort::DequeSort() : unpaired(0), odd(false) {
	// std::cout << "Default constructor for the DequeSort class called" << std::endl;
	this->push_back(std::make_pair(0, 0));
}

DequeSort::DequeSort(const DequeSort& other) : unpaired(0), odd(false) {
	// std::cout << "Copy constructor for the DequeSort class called" << std::endl;
	*this = other;
}

DequeSort::~DequeSort() {
	// std::cout << "Default destructor for the DequeSort class called" << std::endl;
}

DequeSort& DequeSort::operator=(const DequeSort& other) {
	// std::cout << "Copy assignment operator for the DequeSort class called" << std::endl;
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
DequeSort& DequeSort::operator=(const std::deque<std::pair<int, int> >& other) {
	this->clear();
	for (size_t i = 0; i < other.size(); i++)
	{
		this->push_back(other[i]);
	}
	return *this;
}

DequeSort::DequeSort(const char *argv[]) : unpaired(0), odd(false) {
	std::deque<int> tmpDeq;
	setBegin();

	for (size_t i = 1; argv[i]; i++)
	{
		tmpDeq.push_back(static_cast<int>(strtod(argv[i], 0)));
	}


	if (tmpDeq.size() % 2 == 1) {
		odd = true;
		unpaired = tmpDeq.back();
		this->oddPair = std::make_pair(tmpDeq.back(), tmpDeq.back());
		tmpDeq.pop_back();
	}

	for (size_t i = 0; i + 1 < tmpDeq.size(); i+=2)
	{
		this->push_back(std::make_pair(tmpDeq[i], tmpDeq[i + 1]));
	}

	sortPairs();

	*this = mergeSort(*this);

	std::deque<int> sorted;
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

bool DequeSort::isUnpair(int value) {
	if (!odd)
		return false;

	return value == unpaired;
}

bool DequeSort::isUnpair(std::deque<std::pair<int, int> >::iterator& value) {
	if (!odd)
		return false;

	return (*value).first == unpaired;
}

bool DequeSort::isUnpair(std::pair<int, int>& value) {
	if (!odd)
		return false;

	return value.first == unpaired;
}

void DequeSort::setBegin() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	begin_time = tv.tv_usec;
}

void DequeSort::setEnd() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	end_time = tv.tv_usec;
}

std::time_t DequeSort::getTotTime() {
	return end_time - begin_time;
}

std::deque<std::pair<int, int> > DequeSort::mergeSort(std::deque<std::pair<int, int> > split) {
	if (split.size() > 1) {
		// std::cout << split << std::endl;
		size_t half = split.size() / 2;
		std::deque<std::pair<int, int> > low(split.begin(), split.begin() + half);
		std::deque<std::pair<int, int> > high(split.begin() + half, split.end());
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

void DequeSort::sortPairs() {
	for (size_t i = 0; i < this->size(); i++)
	{
		if (this->at(i).first > this->at(i).second) {
			std::swap(this->at(i).first, this->at(i).second);
		}
	}
}

void DequeSort::addBiggerOfPair(std::deque<int>& sorted) {
	for (size_t i = 0; i < this->size(); i++)
	{
		sorted.push_back(this->at(i).second);
	}
}

std::deque<size_t> DequeSort::jacobstyle(size_t j) {
	std::deque<size_t> jacob;
	jacob.push_back(2);
	jacob.push_back(2);
	for (size_t i = 1; i < j; i++)
	{
		size_t val = jacob[i] + (jacob[i - 1] * 2);
		jacob.push_back(val);
	}
	return jacob;
}

std::deque<std::pair<int, int> > DequeSort::jacobsort() {
	std::deque<size_t> jacobSequence = jacobstyle(this->size());
	std::deque<std::pair<int, int> > result;

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

void DequeSort::binaryInsert(std::deque<int>& final, int value, size_t start, size_t end, size_t middle) {
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

std::deque<int> DequeSort::insert(std::deque<int>& final) {
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

size_t DequeSort::findValIndex(std::deque<int>& final, int value) {
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

void DequeSort::isSorted(std::deque<int>& final) {
	for (size_t i = 0; i < final.size() - 1; i++)
	{
		if (final[i] > final[i + 1]) {
			std::cerr << "\x1B[91mList is not sorted\033[0m\n " << final[i] << " " << final[i + 1]  << std::endl;
			return;
		}
	}
	std::cout << "\x1B[92mList is sorted\033[0m\n" << std::endl;
}

std::deque<int>& DequeSort::getSorted() {
	return this->sortedResult;
}
