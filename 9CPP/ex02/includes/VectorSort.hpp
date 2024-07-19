#include <vector>
#include <iostream>
#include <cstdlib>

class VectorSort : public std::vector<std::pair<int, int> > {
  private:
	int unpaired;
	bool odd;
  public:
	VectorSort();
	VectorSort(const char *argv[]);
	VectorSort(const VectorSort& other);
	~VectorSort();
	VectorSort& operator=(const VectorSort& other);
	bool isUnpair(int value);
	bool isUnpair(std::vector<std::pair<int, int> >::iterator& value);
	bool isUnpair(std::pair<int, int>& value);
};

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

inline std::ostream& operator<<(std::ostream& os, std::vector<int> vec) {
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " " << std::flush;
	}
	std::cout << std::endl;
	return os;
}
