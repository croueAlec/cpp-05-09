#pragma once

#include <string>
#include <fstream>
#include <iostream>

class InputFile : public std::ifstream {
private:
	const std::string filename;
public:
	InputFile();
	InputFile(const std::string& filename);
	~InputFile();
	InputFile& operator=(const InputFile& other);

	void checkInput(std::string line, double& wallet);

	class BadDateException : public std::exception {
	  public:
		virtual const char* what() const throw();
	};

	class NegativeNumberException : public std::exception {
	  public:
		virtual const char* what() const throw();
	};

	class NumberTooLargeException : public std::exception {
	  public:
		virtual const char* what() const throw();
	};
};
