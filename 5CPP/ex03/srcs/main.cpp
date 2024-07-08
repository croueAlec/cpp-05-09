#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void invalidForms() {
	Intern marcus;
	std::cout << std::endl;
	try
	{
		marcus.makeForm("Invalid form", "Andy");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << std::endl;
}

void validForms() {
	Intern marcus;
	std::cout << std::endl;

	AForm* one = marcus.makeForm("tree request", "Andrei");

	std::cout << std::endl;
	AForm* two = marcus.makeForm("robotomy request", "Antoine");

	std::cout << std::endl;
	AForm* three = marcus.makeForm("pardon request", "Alec");

	std::cout << std::endl << std::endl << std::endl;
	{
		Bureaucrat artemis("Artemis", 1);

		one->beSigned(artemis);
		one->execute(artemis);
		two->beSigned(artemis);
		two->execute(artemis);
		three->beSigned(artemis);
		three->execute(artemis);
	}
	std::cout << std::endl << std::endl << std::endl;

	std::cout << std::endl;
	delete one;
	std::cout << std::endl;
	delete two;
	std::cout << std::endl;
	delete three;
	std::cout << std::endl;
}

int main(void) {

	validForms();
	std::cout << std::endl << std::endl;
	invalidForms();
	return 0;
}
