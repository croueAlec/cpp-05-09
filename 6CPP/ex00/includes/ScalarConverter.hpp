#pragma once

#include <string>
#include <iostream>
#include <cstdlib>
#include <cmath>

const int MIN_INT = -2147483648;
const int MAX_INT = 2147483647;

class ScalarConverter {
  private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	~ScalarConverter();
	ScalarConverter& operator=(const ScalarConverter& other);

  public:
	static void convert(const std::string& literal);
};
