#include "Form.hpp"

Form::Form() : name("default"), gradeToSign(5), gradeToExecute(5) {
	std::cout << "Default constructor for the Form class called" << std::endl;
}

Form::Form(const std::string name, int sign, int execute) : name(name), gradeToSign(sign), gradeToExecute(execute) {
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

	std::cout << "Default constructor for the Form class called" << std::endl;
}

Form::Form(const Form& other) : name("default"), gradeToSign(5), gradeToExecute(5) {
	std::cout << "Copy constructor for the Form class called" << std::endl;
	*this = other;
}

Form::~Form() {
	std::cout << "Default destructor for the Form class called" << std::endl;
}

Form& Form::operator=(const Form& other) {
	std::cout << "Copy assignment operator for the Form class called" << std::endl;
	if (this != &other) {
		this->sign = other.sign;
	}
	return *this;
}

const std::string Form::getName() {
	return name;
}

bool Form::getSign() {
	return sign;
}

size_t Form::getGradeToSign() const {
	return gradeToSign;
}

size_t Form::getGradeToExecute() const {
	return gradeToExecute;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "The Form can't have a grade above 1";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "The Form can't have a grade below 150";
}

std::ostream& operator<<(std::ostream& ostream, const Form& form) {
	ostream << "This form needs a grade of " << form.getGradeToSign() << " to sign and of " << form.getGradeToExecute() << " to execute";
	return ostream;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (sign)
		throw std::logic_error("Form already signed");
	else if (bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException();
	else
		sign = 1;
}
