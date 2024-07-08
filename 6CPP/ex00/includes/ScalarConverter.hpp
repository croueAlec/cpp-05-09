#pragma once

#include <string>
#include <iostream>

class ScalarConverter {
  private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	~ScalarConverter();
	ScalarConverter& operator=(const ScalarConverter& other);

  public:
	static void convert(std::string& literal);
};
