#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("default") {
	std::cout << "Default constructor for the PresidentialPardonForm class called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), target(target) {
	std::cout << "Parameted constructor for the PresidentialPardonForm class called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) {
	std::cout << "Copy constructor for the PresidentialPardonForm class called" << std::endl;
	*this = other;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "Default destructor for the PresidentialPardonForm class called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	std::cout << "Copy assignment operator for the PresidentialPardonForm class called" << std::endl;
	if (this != &other) {
		this->target = other.target;
		AForm::operator=(other);
	}
	return *this;
}

void PresidentialPardonForm::executeForm(Bureaucrat const & executor) const {
	std::cout << target << ", you have been pardoned for your crimes by president Zaphod Beeblebrox, be grateful" << std::endl;
	(void)executor;
}
