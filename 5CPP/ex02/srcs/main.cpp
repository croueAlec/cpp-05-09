#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <cstdlib>

void trees() {
	{
		Bureaucrat signeur("Signeur", 145);
		Bureaucrat executeur("Executeur", 137);

		ShrubberyCreationForm tree("Jardin");
		tree.beSigned(signeur);
		try
		{
			tree.execute(signeur);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		tree.execute(executeur);
	}

	std::cout << std::endl << std::endl << std::endl;
}

void robot() {
	srand(time(0));

	{
		Bureaucrat signeur("Signeur", 72);
		Bureaucrat executeur("Executeur", 45);

		RobotomyRequestForm human("Human");

		try
		{
			human.execute(executeur);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		human.beSigned(signeur);
		for (size_t i = 0; i < 10; i++)
		{
			std::cout << std::endl;
			human.execute(executeur);
		}
		std::cout << std::endl;
	}
}

void pardon() {
	{
		Bureaucrat signeur("Signeur", 25);
		Bureaucrat executeur("Executeur", 5);

		PresidentialPardonForm pardonForm("Henri");

		pardonForm.beSigned(signeur);
		try
		{
			std::cout << std::endl;
			pardonForm.beSigned(executeur);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		try
		{
			std::cout << std::endl;
			pardonForm.execute(signeur);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		std::cout << std::endl;
		pardonForm.execute(executeur);
		std::cout << std::endl;
		pardonForm.execute(executeur);
		std::cout << std::endl;
	}
}

int main(void)
{

	// trees();

	// robot();

	// pardon();

	//TODO: tests for executeForm

	return 0;
}
