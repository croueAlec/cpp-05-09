#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default") {
	std::cout << "Default constructor for the ShrubberyCreationForm class called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {
	std::cout << "Parameted constructor for the ShrubberyCreationForm class called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm("ShrubberyCreationForm", 145, 137), target(other.target) {
	std::cout << "Copy constructor for the ShrubberyCreationForm class called" << std::endl;
	*this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Default destructor for the ShrubberyCreationForm class called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	std::cout << "Copy assignment operator for the ShrubberyCreationForm class called" << std::endl;
	if (this != &other) {
		this->target = other.target;
		AForm::operator=(other);
	}
	return *this;
}

void ShrubberyCreationForm::executeForm(Bureaucrat const & executor) const {
	try
	{
		std::string fileName = target;
		std::ofstream tree;
		fileName.append("_shrubbery");
		tree.open(fileName.c_str());
		tree << TREE;
		tree << TREE;
		tree.close();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	(void)executor;
}
