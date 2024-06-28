#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat	andrei("Andrei", 1);
		std::cout << andrei << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat	High("High", 0);
	}
	catch(const Bureaucrat::GradeTooHighException e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const Bureaucrat::GradeTooLowException e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat	Low("Low", 151);
	}
	catch(const Bureaucrat::GradeTooHighException e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const Bureaucrat::GradeTooLowException e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}

