#include "AForm.hpp"

AForm::AForm() : name("default"), gradeToSign(5), gradeToExecute(5) {
	std::cout << "Default constructor for the AForm class called" << std::endl;
}

AForm::AForm(const std::string name, int sign, int execute) : name(name), gradeToSign(sign), gradeToExecute(execute) {
	if (sign < 1) {
		throw GradeTooHighException();
	}
	if (sign > 150) {
		throw GradeTooLowException();
	}

	if (execute < 1) {
		throw GradeTooHighException();
	}
	if (execute > 150) {
		throw GradeTooLowException();
	}

	std::cout << "Default constructor for the AForm class called" << std::endl;
}

AForm::AForm(const AForm& other) : name("default"), gradeToSign(5), gradeToExecute(5) {
	std::cout << "Copy constructor for the AForm class called" << std::endl;
	*this = other;
}

AForm::~AForm() {
	std::cout << "Default destructor for the AForm class called" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
	std::cout << "Copy assignment operator for the AForm class called" << std::endl;
	if (this != &other) {
		this->sign = other.sign;
	}
	return *this;
}

const std::string AForm::getName() {
	return name;
}

bool AForm::getSign() {
	return sign;
}

size_t AForm::getGradeToSign() const {
	return gradeToSign;
}

size_t AForm::getGradeToExecute() const {
	return gradeToExecute;
}

void AForm::execute(Bureaucrat const & executor) const {
	if (!sign)
		throw FormNotSignedException();
	if (executor.getGrade() > this->gradeToExecute)
		throw GradeTooLowException();
	this->executeForm(executor);
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed";
}

std::ostream& operator<<(std::ostream& ostream, const AForm& form) {
	ostream << "This form needs a grade of " << form.getGradeToSign() << " to sign and of " << form.getGradeToExecute() << " to execute";
	return ostream;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (sign)
		throw std::logic_error("AForm already signed");
	else if (bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException();
	else
		sign = 1;
}
