#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <cstdlib>

const std::string DATABASE_PATH = "data.csv";
const int NBR_DAYS_IN_MONTH[] = {31, 28, 31, 30, 31, 30,
										31, 31, 30, 31, 30, 31};

class Database : public std::ifstream {
  private:
	std::map<std::string, double> database;
  public:
	Database();
	Database(const Database& other);
	~Database();
	Database& operator=(const Database& other);

	bool valid();

	static bool isLeap(int year);
	static bool checkDate(std::string line);
	bool checkLine(std::string line, size_t i, double& value);

	void parseDatabase();
	std::map<std::string, double>& getDB();

	void printValue(const std::string key, double wallet);
};
