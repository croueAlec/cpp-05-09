#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
	std::cout << "Default constructor for the Intern class called" << std::endl;
}

Intern::Intern(const Intern& other) {
	std::cout << "Copy constructor for the Intern class called" << std::endl;
	*this = other;
}

Intern::~Intern() {
	std::cout << "Default destructor for the Intern class called" << std::endl;
}

Intern& Intern::operator=(const Intern& other) {
	std::cout << "Copy assignment operator for the Intern class called" << std::endl;
	(void)other;
	return *this;
}

const char* Intern::BadFormNameException::what() const throw() {
	return "Invalid form name";
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
	std::string forms[3] = {"tree request", "robotomy request", "pardon request"};

	size_t i = 0;
	for (i = 0; i < 3; i++)
	{
		if (formName == forms[i]) {
			break;
		}
	}
	switch (i)
	{
	case 0:
		return new ShrubberyCreationForm(target);
		break;

	case 1:
		return new RobotomyRequestForm(target);
		break;

	case 2:
		return new PresidentialPardonForm(target);
		break;
	
	default:
		throw BadFormNameException();
		break;
	}
	return NULL;
}
