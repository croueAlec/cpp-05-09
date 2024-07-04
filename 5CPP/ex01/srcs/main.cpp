#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat signeur("Signeur", 5);
	Bureaucrat nonSigneur("nonSigneur", 3);

	try
	{
		Form inscription("Inscription administrative", 5, 3);
		signeur.signForm(inscription);
		nonSigneur.signForm(inscription);
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Form badForm("Bad Form", 0, 8);
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Form otherBadForm("Other Bad Form", 8, 151);
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}

