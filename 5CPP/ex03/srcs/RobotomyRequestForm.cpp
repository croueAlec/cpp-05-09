#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default") {
	std::cout << "Default constructor for the RobotomyRequestForm class called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), target(target) {
	std::cout << "Parameted constructor for the RobotomyRequestForm class called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) {
	std::cout << "Copy constructor for the RobotomyRequestForm class called" << std::endl;
	*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "Default destructor for the RobotomyRequestForm class called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	std::cout << "Copy assignment operator for the RobotomyRequestForm class called" << std::endl;
	if (this != &other) {
		this->target = other.target;
		AForm::operator=(other);
	}
	return *this;
}

void RobotomyRequestForm::executeForm(Bureaucrat const & executor) const {
	std::cout << "* drilling noises *" << std::endl;
	if (rand() % 2)
		std::cout << target << " has successfully been Robotomized" << std::endl;
	else
		std::cout << target << " could not be Robotomized" << std::endl;
	(void)executor;
}
