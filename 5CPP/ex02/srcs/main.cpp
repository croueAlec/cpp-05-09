#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"


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

int main(void)
{

	trees();

	return 0;
}

