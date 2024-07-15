#include "InputFile.hpp"
#include "Database.hpp"

InputFile::InputFile() : filename("invalid") { }

InputFile::InputFile(const std::string& filename) : filename(filename) {
	this->open(filename.c_str());
	if (this->fail()) {
		std::cerr << "Error: could not open file" << std::endl;
	}
}

InputFile::~InputFile() {
	this->close();
}

InputFile& InputFile::operator=(const InputFile& other) {
	if (this != &other) {

	}
	return *this;
}

void InputFile::checkInput(std::string line, double& wallet) {
	if (line.size() < 14 || !Database::checkDate(line))
		throw BadDateException();

	if (line.substr(10, 3) != " | ")
		throw BadDateException();

	line = line.substr(13, line.size() - 13);
	char *end;
	wallet = strtod(line.c_str(), &end);
	if (*end)
		throw BadDateException();

	if (wallet <= 0)
		throw NegativeNumberException();

	if (wallet >+ 1000)
		throw NumberTooLargeException();
}

const char* InputFile::BadDateException::what() const throw() {
	return "Error: Bad input = > ";
}

const char* InputFile::NegativeNumberException::what() const throw() {
	return "Error: not a positive number.";
}

const char* InputFile::NumberTooLargeException::what() const throw() {
	return "Error: too large a number.";
}
