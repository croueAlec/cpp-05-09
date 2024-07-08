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
			std::cout << "ici" << std::endl;
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

void executeFormTest() {
	{
		Bureaucrat signeur("Signeur", 17);
		Bureaucrat executeur("Executeur", 1);

		ShrubberyCreationForm tree("executed");
		RobotomyRequestForm bot("mr_r0bo7");
		PresidentialPardonForm president("Henri");

		tree.beSigned(signeur);
		try
		{
			std::cout << std::endl;
			signeur.executeForm(tree);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		try
		{
			std::cout << std::endl;
			executeur.executeForm(bot);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		president.beSigned(executeur);
		try
		{
			std::cout << std::endl;
			executeur.executeForm(president);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << std::endl;
	}
}

int main(void) {

	std::cout << "Shrubbery" << std::endl;
	trees();
	std::cout << "Robot" << std::endl;
	robot();
	std::cout << "Pardon" << std::endl;
	pardon();
	std::cout << "Exec Form" << std::endl;
	executeFormTest();

	return 0;
}
