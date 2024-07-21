#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sys/time.h>
#include <unistd.h>

class VectorSort : public std::vector<std::pair<int, int> > {
  private:
	int unpaired;
	bool odd;
	std::time_t begin_time;
	std::time_t end_time;
  public:
	VectorSort();
	VectorSort(const char *argv[]);
	VectorSort(const VectorSort& other);
	~VectorSort();
	VectorSort& operator=(const VectorSort& other);
	VectorSort& operator=(const std::vector<std::pair<int, int> >& other);

	bool isUnpair(int value);
	bool isUnpair(std::vector<std::pair<int, int> >::iterator& value);
	bool isUnpair(std::pair<int, int>& value);

	void setBegin();
	void setEnd();
	std::time_t getTotTime();

	std::vector<std::pair<int, int> > mergeSort(std::vector<std::pair<int, int> > split);
	void sortPairs();

	void addBiggerOfPair(std::vector<int>& sorted);

	std::vector<size_t> jacobstyle(size_t j);
	std::vector<std::pair<int, int> > jacobsort();

	void binaryInsert(std::vector<int>& final, int value, size_t start, size_t end, size_t middle);
	std::vector<int> insert(std::vector<int>& final);
	size_t findValIndex(std::vector<int>& final, int value);
};

inline std::vector<std::pair<int, int> > operator+(std::vector<std::pair<int, int> >& low, std::vector<std::pair<int, int> >& high) {
	std::vector<std::pair<int, int> > tmp;
	size_t i, j;
	for (i = 0, j = 0; i < high.size() && j < low.size(); )
	{
		if (i < high.size() && high[i].second < low[j].second) {
			tmp.push_back(high[i]);
			i++;
		} else if (j < low.size() && low[j].second < high[i].second) {
			tmp.push_back(low[j]);
			j++;
		}
	}
	while (i < high.size())
	{
		tmp.push_back(high[i++]);
	}
	while (j < low.size())
	{
		tmp.push_back(low[j++]);
	}
	return tmp;
}

inline std::ostream& operator<<(std::ostream& os, VectorSort& tmp) {
	for (size_t i = 0; i < tmp.size(); i++)
	{
		if (tmp.isUnpair(tmp[i])) {
			std::cout << tmp[i].first << " " << std::flush;
			continue;
		}
		std::cout << tmp[i].first << "_" << tmp[i].second << " " << std::flush;
	}
	std::cout << std::endl;

	return os;
}

template<typename T>
inline std::ostream& operator<<(std::ostream& os, std::vector<T>& vec) {
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " " << std::flush;
	}
	std::cout << std::endl;
	return os;
}

inline std::ostream& operator<<(std::ostream& os, std::vector<std::pair<int, int> >& vec) {
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << (vec[i]).second << " " << std::flush;
	}
	std::cout << std::endl;
	return os;
}
