#include "Database.hpp"

Database::Database() {
	this->open(DATABASE_PATH.c_str());
	if (this->fail()) {
		std::cerr << "Error: could not open file" << std::endl;
	}

	parseDatabase();
}

Database::Database(const Database& other) {
	*this = other;
}

Database::~Database() {
	this->close();
}

Database& Database::operator=(const Database& other) {
	if (this != &other) {
		this->database = other.database;
	}
	return *this;
}

bool Database::valid() {
	return (this->database.empty());
}

bool Database::isLeap(int year) {
	if ((year % 4 == 0 && year % 100) || year % 400 == 0)
		return true;
	else
		return false;
}

bool Database::checkDate(std::string line) {
	char *end = NULL;
	double year = strtod(line.c_str(), &end);
	if (year < 2009 || year > 2025 || *end != '-')
		return false;

	line = line.substr(5, line.size() - 5);
	double month = strtod(line.c_str(), &end);
	if (month < 0 || month > 12 || *end != '-')
		return false;

	line = line.substr(3, line.size() - 3);
	double days = strtod(line.c_str(), &end);
	if (isLeap(static_cast<int>(year)) && month == 2) {
		return (days <= 29 ? true : false);
	}

	if (NBR_DAYS_IN_MONTH[static_cast<int>(month) - 1] < days)
		return false;
	else
		return true;
}

bool Database::checkLine(std::string line, size_t i, double& value) {
	if (line.size() < 12 || line[10] != ',')
		return false;
	std::string tmp;
	tmp = line.substr(11, line.size() - 11);
	char *end = NULL;
	value = strtod(tmp.c_str(), &end);
	if (*end || value < 0 || !checkDate(line)) {
		std::cerr << "Invalid database at line " << i << std::endl;
		return false;
	}
	else
		return true;
}

void Database::parseDatabase() {
	std::string tmp;
	if (this->is_open() && this->good()) {
		*this >> tmp;
		if (tmp != "date,exchange_rate") {
			std::cerr << "Invalid database, missing header" << std::endl;
			return ;
		}
	}

	size_t i = 2;
	while (this->is_open() && this->good())
	{
		double value = 0;
		*this >> tmp;
		// std::cout << tmp << std::endl;
		if (!checkLine(tmp, i, value)) {
			database.clear();
			return ;
		}
		database[tmp.substr(0, 10)] = value;
		i++;
	}
}

std::map<std::string, double>& Database::getDB() {
	return database;
}

void Database::printValue(const std::string key, double wallet) {
	std::map<std::string, double>::iterator it = this->database.lower_bound(key);
	if (this->database.find(key) == this->database.end()) {
		if (it != this->database.begin())
			it--;
		double mult = (*it).second * wallet;
		std::cout << key << " => " << wallet << " = " << mult << std::endl;
	} else {
		it = this->database.find(key);
		double mult = (*it).second * wallet;
		std::cout << key << " => " << wallet << " = " << mult << std::endl;
	}
}
