#include "InputFile.hpp"
#include "Database.hpp"

void calculateDatabase(InputFile& input, Database& db) {
	std::string line;
	if (input.is_open() && input.good()) {
		std::getline(input, line);
		if (line != "date | value") {
			std::cerr << "Invalid file, missing header" << std::endl;
			return;
		}
	}

	while (input.is_open() && input.good())
	{
		std::getline(input, line);
		if (line.empty())
			return;
		double wallet = 0;
		try
		{
			input.checkInput(line, wallet);
		}
		catch(InputFile::BadDateException& e)
		{
			std::cerr << e.what() << line << std::endl;
			continue;
		}
		catch(InputFile::NegativeNumberException& e)
		{
			std::cerr << e.what() << std::endl;
			continue;
		}
		catch(InputFile::NumberTooLargeException& e)
		{
			std::cerr << e.what() << std::endl;
			continue;
		}
		db.printValue(line.substr(0, 10), wallet);
	}
}

int main(int argc, char const *argv[])
{
	if (argc != 2) {
		std::cerr << "Error: could not open file" << std::endl;
		return 1;
	}

	std::string filename(argv[1]);
	InputFile input(filename);
	if (input.fail())
		return 1;

	Database database;
	if (database.fail() && database.valid())
		return 1;

	// std::cout << "Map is not empty " << database.getDB().size() << std::endl;

	calculateDatabase(input, database);

	return 0;
}
